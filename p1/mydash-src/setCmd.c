#include "setCmd.h"
#include "Job.h"
#include <string.h>

const char* delimiter = " ";

int setLine(JobPtr job, char *line){
	int length = getLength(line);
	job->line = (char *) malloc(sizeof(char) * length+1);
	strcpy(job->line, line);
	if(job->line == NULL){
		return 0;
	}
	return 1;
}

int getLength(char *line){
	return strlen(line);
}

int setFlags(JobPtr job, char *line){
	int numberOfFlags = -1;
	char *token = strtok(line, delimiter);
	while(token && numberOfFlags < 2048){
		char *backgroundJob = strchr(token, '&');
		if(backgroundJob){
			job->backgroundJob = 1;
			*backgroundJob = '\0';
		}
		if(getLength(token)){
			job->flags[++numberOfFlags] = (char *)malloc(sizeof(char)* MAX_COM_LENGTH);
			strcpy(job->flags[numberOfFlags], token);
		}
		if(job->backgroundJob){
			token = NULL;
		}
		else{
			token = strtok(NULL, delimiter);
		}
	}
	job->numberOfFlags = numberOfFlags;
	job->flags[numberOfFlags+1] = NULL;
	return -1;
}

int setCommand(JobPtr job, char *line){
	char *temp = (char *) malloc(sizeof(char) * MAX_COM_LENGTH);
	strcpy(temp, line);
	job->command = (char *) malloc(sizeof(char) * MAX_COM_LENGTH);
	strcpy(job->command, strtok(temp, delimiter));
	free(temp);
	if(job->command == NULL){
		return 0;
	}
	return 1;
}
