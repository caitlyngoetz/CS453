#include <stdio.h>
#include <stdlib.h>
#include "ourhdr.h"
#include <unistd.h>
#include "List.h"
#include "common.h"
#include "Job.h"
#include <readline/history.h>
#include <readline/readline.h>
#include "run.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <pwd.h>
#include <string.h>

char *toString(const void *);
void freeJob(void *);
int equals(const void *, const void *);
void jobs(ListPtr list, int printIt);
int runJob(ListPtr list, JobPtr job);
int run(ListPtr list, JobPtr job);
void addJob(ListPtr list, JobPtr job);
void changeDirectory(char *path);

struct passwd *pwd;

int runPrompt(char *prompt){
	char *line = NULL;
	JobPtr job = NULL;
	ListPtr list = createList(equals, toString, freeJob);

	using_history();

	while ((line=readline(prompt))) {
		job = createJob(line);
		free(line);

		if(job != NULL){
			switch(runJob(list,job)){
				case -2:
					freeJob(job);
					freeList(list);
					return -2;
			
				case 0:
					freeJob(job);
					freeList(list);
					return 0;

				case 1:
					add_history(job->line);
					if(!job->backgroundJob)
						freeJob(job);
						
			}
			job = NULL;
		
		}
		jobs(list, 0);
	}

	freeList(list);

	if(line==NULL){
		if(job != NULL){
			freeJob(job);
		}	
	}
	return 0;

}

int runJob(ListPtr list, JobPtr job){
	char *command = job->command;
	if(!strcmp(command, "exit")){
		return 0;
	}else if(!strcmp(command, "cd")){
		changeDirectory((job->flags)[1]);
	}else if(!strcmp(command, "jobs")){
		jobs(list, 1);
		return 1;
	}else{
		return run(list, job);
	}
	return 1;	
}

int run(ListPtr list, JobPtr job){
	int status = 1;
	if((job->id = fork()) == 0){
		execvp(job->command, job->flags);
		printf("unknown command\n");
		exit(-1);
	}
	if(job->backgroundJob){
		addJob(list, job);
		printf("[%d] %d %s\n", job->index, job->id, job->line);
	}
	else if(waitpid(job->id, NULL, 0) < 0){
		status = -2;
	}
	return status;
}

void changeDirectory(char *path){
	if(path == NULL){
		uid_t id = getuid();
		struct passwd *pwd = getpwuid(id);
		path = pwd->pw_dir;
	}
	if(chdir(path) < 0){
		printf("Directory does not exist!\n");
	}
}
