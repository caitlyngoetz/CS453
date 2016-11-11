#ifndef __JOB_H
#define __JOB_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include "common.h"

#define MAX_COM_LENGTH 255
#define JOB_RUNNING 1
#define JOB_DONE 2

typedef struct job Job;
typedef struct job * JobPtr;

struct job {
	pid_t id;
	char *line;
	char *command;
	char *flags[2048+2];
	int index;
	int state;
	int numberOfFlags;
	int backgroundJob;
};

JobPtr createJob(char *);
char *toString(const void *);
void freeJob(void *);
int equals(const void *, const void *);

#endif
