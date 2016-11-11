#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <pthread.h>
#include "FileAccess.h"

void *threadMain(void *);
pthread_t *threads;

FileAccessPtr fileAccessor;

int numThreads;
int max_sum;
int iterations;

pthread_mutex_t mutex;

long int get_my_index()
{
	int i;
	pthread_mutex_lock(&mutex);
	for(i=0; i<numThreads; i++) {
		if(threads[i] == pthread_self()) {
			pthread_mutex_unlock(&mutex);
			return i+1;
		}
	}
	pthread_mutex_lock(&mutex);
	return -1;
}

void *threadMain(void *arg)
{
	int i;
	int period;
	long int id = get_my_index();
	printf("Thread %ld starting up.\n", id);

	for(i=0; i<iterations; i++) {
		fileAccessor->startAccess(fileAccessor, id);
		printf("Thread %ld starting file access.\n", id);
		period = (random() % 5 + 1) * 100;
		usleep(period);
		fileAccessor->endAccess(fileAccessor, id);
		printf("Thread %ld ending file access.\n", id);
		period = (random() % 5 + 1) * 100;
		usleep(period);
	}
	pthread_exit(NULL);
}

void signalHandler(int signal)
{
	printf("ALARM!!! ALARM!!! ALARM!!! TIMEOUT!!\n");
	exit(0);
}
int main(int argc, char **argv)
{
	int i;

	if(argc < 3) {
		fprintf(stderr, "Usage: %s <numThreads> <max sum> <iterations>\n", argv[0]);
		exit(1);
	}

	numThreads = atoi(argv[1]);
	max_sum = atoi(argv[2]);
	iterations = atoi(argv[3]);

	fileAccessor = fileaccess_init(max_sum);

	signal(SIGALRM, signalHandler);
	alarm(30);

	pthread_mutex_init(&mutex, NULL);
	threads = (pthread_t *) malloc(sizeof(pthread_t) * numThreads);
	for(i=0; i<numThreads; i++) {
		pthread_create(&threads[i], NULL, threadMain, (void *) NULL);
	}

	for(i=0; i<numThreads; i++) {
		pthread_join(threads[i], NULL);
	}

	pthread_mutex_destroy(&mutex);
	free(threads);
	free(fileAccessor);
	exit(0);
}

