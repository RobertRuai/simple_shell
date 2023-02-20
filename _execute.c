#include "main.h"

/**
 * _execute - executes commands entered by users
 *@command: command input
 *@args: vector array of pointers to commands
 * Return: 0
 */
void _execute(char *command, char **args)
{
	char *actual_command = NULL;
	pid_t pid;
	int status;

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		exit(1);
	}
	else if (pid == 0)
	{
		command = args[0];
		actual_command = find_path(command);
		if (execv(actual_command, args) < 0)
		{
			perror("execv");
			exit(1);
		}
	}
	else
	{
		wait(&status);
	}
}
