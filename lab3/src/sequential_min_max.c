#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "find_min_max.h"
#include "utils.h"

typedef struct someArgs_tag {
    int *array;
    int n;
    int m;
} someArgs_t;

struct MinMax min_max;

void* findminmax(void *args)
{
    someArgs_t *arg = (someArgs_t*) args;
    min_max = GetMinMax(arg->array, arg->n, arg->m);
    //printf("min: %d\n", min_max.min);
    //printf("max: %d\n", min_max.max);
}



#define NUM_THREADS 2

int main(int argc, char **argv) {
    pthread_t threads[NUM_THREADS];
    
  if (argc != 3) {
    printf("Usage: %s seed arraysize\n", argv[0]);
    return 1;
  }

  int seed = atoi(argv[1]);
  if (seed <= 0) {
    printf("seed is a positive number\n");
    return 1;
  }

  int array_size = atoi(argv[2]);
  if (array_size <= 0) {
    printf("array_size is a positive number\n");
    return 1;
  }
  someArgs_t args[NUM_THREADS];
  int blocksize = array_size / NUM_THREADS;
  int status;
  int i;
  int *array = malloc(array_size * sizeof(int));
  GenerateArray(array, array_size, seed);
  struct timeval start_time;
  gettimeofday(&start_time, NULL);
  for (i = 0; i < NUM_THREADS; i++) {
      args[i].array = array;
      args[i].n = i*blocksize + 1;
      args[i].m = args[i].n + blocksize;
      }
      
      for (i = 0; i < NUM_THREADS; i++) {
          status = pthread_create(&threads[i], NULL, (void*)findminmax, (void*) &args[i]);
          if (status != 0) {
              printf("main error: can't create thread, status = %d\n", status);
              }
              }
 struct timeval finish_time;
  gettimeofday(&finish_time, NULL);
  //struct MinMax min_max = GetMinMax(array, 0, array_size);
  free(array);
  
  double elapsed_time = (finish_time.tv_sec - start_time.tv_sec) * 1000.0;
  elapsed_time += (finish_time.tv_usec - start_time.tv_usec) / 1000.0;

  printf("min: %d\n", min_max.min);
  printf("max: %d\n", min_max.max);
  printf("Elapsed time: %fms\n", elapsed_time);

  return 0;
}
