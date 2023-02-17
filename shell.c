#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 1024

/**
 * main - shell prompt \n
 *
 * Return: exit code 0 on success and non-zero status codes
 */
int main()
{
	char *command = NULL;
	size_t command_size = 0;
	char *args[2];
	int pid, status;

	while (1)
	{
		printf("#cisfun$ ");
		fflush(stdout);

		if (getline(&command, &command_size, stdin) == -1)
		{
			perror("getline");
			exit(1);
		}

		/* rm newline character from input */
		command[strcspn(command, "\n")] = '\0';
		args[0] = command;
		args[1] = NULL;

		pid = fork();

		if (pid < 0)
		{
			perror("fork");
			exit(1);
		}
		else if (pid == 0)
		{
			if (execv(args[0], args) < 0)
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

	free(command);

	return (0);
}
