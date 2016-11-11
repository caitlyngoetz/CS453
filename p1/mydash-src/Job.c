#include "Job.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <sys/wait.h>
#include "List.h"
#include "setCmd.h"

JobPtr createJob(char *line){
	int len = getLength(line);
	if(len < 1 || len > MAX_COM_LENGTH){
		return NULL;
	}

	JobPtr newJob = (JobPtr) malloc (sizeof(Job));
	newJob->index = 0;
	newJob->numberOfFlags = 0;
	newJob->state = JOB_RUNNING;
	newJob->backgroundJob = 0;
	
	if(!setLine(newJob, line)){
		free(newJob);
		return NULL;
	}
	if(!setCommand(newJob, line)){
		free(newJob->line);
		free(newJob);
		return NULL;
	}
	if(!setFlags(newJob, line)){
		free(newJob->line);
		free(newJob->command);
		free(newJob);
		return NULL;
	}
	return newJob;
}

void freeJob(void *job){
	JobPtr myJob = (JobPtr) job;
	if(myJob == NULL){
		return;
	}
	free(myJob->line);
	free(myJob->command);
	
	int i;
	for(i=0; i<myJob->numberOfFlags+1; i++){
		free((myJob->flags)[i]);
	}
	free(myJob);
}

char *toString(const void *job){
	JobPtr myJob = (JobPtr) job;
	if(myJob == NULL){
		return NULL;
	}
	char *state = "Done";
	if(myJob->state == JOB_RUNNING){
		state = "Running";
	}
	printf("[%d] %s %s\n", myJob->index, state, myJob->line);
	return "";
}

void addJob(ListPtr list, JobPtr job){
	NodePtr node = createNode(job);
	addAtRear(list, node);
	job->index = getSize(list);
}

void removeJob(ListPtr list, NodePtr node){
	removeNode(list, node);
	freeNode(node, freeJob);
}

int equals (const void *job1, const void *job2){
	return 0;
}

void jobs(ListPtr list, int printIt){
	if(!list || isEmpty(list)){
		return;
	}
	pid_t id;
	int status = 0;
	NodePtr node = list->head;
	while(node != NULL){
		JobPtr job = (JobPtr) node->obj;
		if((id = waitpid(job->id, &status, WNOHANG)) < 0){
			return;
		}
		if(id > 0){
			job->state = JOB_DONE;
			toString(job);
			NodePtr next = node->next;
			removeJob(list, node);
			node = next;	
		}else{
			if(printIt){
				toString(job);
			}
			node = node->next;
		}
	}
}

void print(ListPtr list){
	printList(list);
}
