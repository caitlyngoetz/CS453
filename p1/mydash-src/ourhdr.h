/* I made this header so it needs to be after all the other headers at the beginning of programs */

#ifndef _OURHDR_H
#define _OURHDR_H

#include <sys/types.h> /* needed for some prototypes */
#include <stdio.h>
#include <stdlib.h>
#include <sysexits.h>
#include <string.h>
#include <unistd.h>

#define MAXLINE 4096 /*obviously the max line length*/
#define FILE_MODE (S_IRUSR | S_IWUSER | S_IRGRP | S_IROTH) /*default file access permissions*/
#define DIR_MODE (FILE_MODE | S_IXUSR | S_IXGRP | S_IXOTH) /*default permissions*/

/*prototypes for new functions*/

void err_dump(const char *, ...); /* {App misc_source} */
void err_msg(const char *, ...);
void err_quit(const char *, ...);
void err_ret(const char *, ...);
void err_sys(const char *, ...);

#endif	/* _OURHDR_H */
