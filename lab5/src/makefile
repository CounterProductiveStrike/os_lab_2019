CC=gcc
CFLAGS=-I.

all: mutex no_mutex factorial deadlock

mutex : mutex.c
	$(CC) mutex.c -o mutex -lpthread $(CFLAGS)
	
no_mutex : no_mutex.c
	$(CC) no_mutex.c -o no_mutex -lpthread $(CFLAGS)
	
factorial : factorial.c
	$(CC) factorial.c -o factorial -lpthread $(CFLAGS)

deadlock : deadlock.c
	$(CC) deadlock.c -o deadlock -lpthread $(CFLAGS)

clean :
	rm no_mutex mutex factorial deadlock