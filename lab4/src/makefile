CC=gcc
CFLAGS=-I.

all : parallel_min_max utils.o find_min_max.o zombie process_memory parallel_sum

parallel_min_max : utils.o find_min_max.o utils.h find_min_max.h
	$(CC) -o parallel_min_max utils.o find_min_max.o parallel_min_max.c $(CFLAGS)

utils.o : utils.h
	$(CC) -o utils.o -c utils.c $(CFLAGS)

find_min_max.o : utils.h find_min_max.h
	$(CC) -o find_min_max.o -c find_min_max.c $(CFLAGS)
	
zombie : zombie.c
	$(CC) -o zombie zombie.c
	
process_memory : process_memory.c
	$(CC) -o process_memory process_memory.c
	
parallel_sum : utils.o utils.h 
	$(CC) -g -pthread -o parallel_sum utils.o parallel_sum.c $(CFLAGS)

clean :
	rm parallel_min_max utils.o find_min_max.o zombie process_memory parallel_sum