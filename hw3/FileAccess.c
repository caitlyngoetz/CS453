#include "FileAccess.h"

static void __startAccess(FileAccessPtr accessor, long int id);
void startAccess(FileAccessPtr accessor, long int id);
static void __endAccess(FileAccessPtr accessor, long int id);
void endAccess(FileAccessPtr accessor, long int id);

FileAccessPtr fileaccess_init(long int max) {
	FileAccessPtr accessor = (FileAccessPtr) malloc(sizeof(FileAccess));
	accessor->sum = 0;
	accessor->max = max;
	accessor->startAccess = startAccess;
	accessor->endAccess = endAccess;
	pthread_mutex_init(&(accessor->mutex), NULL);
	pthread_cond_init(&(accessor->waitForAccess), NULL);
	return accessor;
}

void startAccess(FileAccessPtr accessor, long int id) {
	pthread_mutex_lock(&(accessor->mutex));
	__startAccess(accessor, id);
	pthread_mutex_unlock(&(accessor->mutex));
}

static void __startAccess(FileAccessPtr accessor, long int id) {
	while((accessor->sum + id) > accessor->max) {
		pthread_cond_wait(&(accessor->waitForAccess), &(accessor->mutex));
	}
	accessor->sum += id;
}

void endAccess(FileAccessPtr accessor, long int id) {
	pthread_mutex_lock(&(accessor->mutex));
	__endAccess(accessor, id);
	pthread_mutex_unlock(&(accessor->mutex));
}

static void __endAccess(FileAccessPtr accessor, long int id) {
	accessor->sum -= id;
	pthread_cond_broadcast(&(accessor->waitForAccess));
}
