#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "ourhdr.h"
#include <unistd.h>
#include <pwd.h>
#include <sys/wait.h>
#include "List.h"
#include "common.h"
#include "Job.h"
#include "run.h"

char* git_version(void);
int runPrompt(char *prompt);

const char *DASH_PROMPT = "DASH_PROMPT";

int main(int argc, char *argv[]) {
	
	char *svnversion = git_version();
	char *prompt = "my_dash> ";
//	int status;
	
	if(argc ==1){
		char *env = getenv(DASH_PROMPT);
		if(env){
			int length = strlen(env);
			prompt = (char *) malloc(sizeof(char) * length+2);
			strcpy(prompt, env);	//protects the env string
		}
		runPrompt(prompt);
	}
	else if(argc == 2){	
		if(strcmp(argv[1],"-v") == 0) {
			printf("Version: %s\n", svnversion);
			printf("Exitting the shell\n");
			exit(0);
		}else{
			printf("Invalid argument: %s!", argv[1]);
		}
	}
}



