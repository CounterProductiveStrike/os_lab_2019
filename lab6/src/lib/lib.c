#include <errno.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#include <ctype.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

#include <getopt.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <sys/socket.h>
#include <sys/types.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>

#include <getopt.h>
uint64_t MultModulo(uint64_t a, uint64_t b, uint64_t mod)
{
	uint64_t result = 0;
	a = a % mod;
	while (b > 0)
	{
		if (b % 2 == 1)
			result = (result + a) % mod;
		a = (a * 2) % mod;
		b /= 2;
	}

	return result % mod;
}