#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define SERV_PORT 10050
#define BUFSIZE 100
#define SADDR struct sockaddr

int main(int argc, char *argv[]) {
  const size_t kSize = sizeof(struct sockaddr_in);
  int bufSize = -1;
  int lfd, cfd;
  int nread;
  char buf[BUFSIZE];
  struct sockaddr_in servaddr;
  struct sockaddr_in cliaddr;
  
  if (argc < 2) {
    printf("Too few arguments \n");
    exit(1);
  }

  if ((lfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket");
    exit(1);
  }
  
  bufSize = atoi(argv[1]);
  if(bufSize == -1){
      printf("Wait, that's illegal\n");
      exit(1);
  }
  //buf = (char*) malloc(bufSize + 1);
  

  memset(&servaddr, 0, kSize);
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
  servaddr.sin_port = htons(SERV_PORT);
    printf("%x\n", SERV_PORT);
  printf("%s\n", inet_ntoa(servaddr.sin_addr));
  printf("%x\n", servaddr.sin_port);

  if (bind(lfd, (SADDR *)&servaddr, kSize) < 0) {
    perror("bind");
    exit(1);
  }

  if (listen(lfd, 5) < 0) {
    perror("listen");
    exit(1);
  }

  while (1) {
    unsigned int clilen = kSize;

    if ((cfd = accept(lfd, (SADDR *)&cliaddr, &clilen)) < 0) {
      perror("accept");
      exit(1);
    }
    printf("connection established\n");

    while ((nread = read(cfd, buf, BUFSIZE)) > 0) {
      write(1, &buf, nread);
    }

    if (nread == -1) {
      perror("read");
      exit(1);
    }
    close(cfd);
  }
  //free(buf);
}