#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>

/*prototypes*/
void _execute(char *command, char **args);
char *find_path(char *command);

#endif /* MAIN_H */
