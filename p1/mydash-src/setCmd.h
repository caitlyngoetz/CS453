#ifndef __SETCMD_H
#define __SETCMD_H

#include "Job.h"
#include <string.h>

int setCommand(JobPtr job, char *line);
int setFlags(JobPtr job, char *line);
int setLine(JobPtr job, char *line);
int getLength(char *line);

#endif
