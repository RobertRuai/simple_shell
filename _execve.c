#include "shell.h"

/**
 * execute_command - execute a command with arguments using fork & execve
 * @args: the arguments to pass to the command
 *
 * Return: 1 for infinite shell iteration, 0 on_exit (success)
 */
int execute_command(char **args)
{
	pid_t pid;
	int status;

	if (args[0] == NULL)
	{
		return (1);
	}

	/* exit shell */
	if (strcmp(args[0], "exit") == 0)
		exit(0);

	pid = fork();
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			printf("%s: command not found\n", args[0]);
		}
		exit(1);
	}
	else if (pid < 0)
	{
		perror("execvp");
	}
	else
	{
		while (waitpid(pid, &status, 0) != pid)
		{
			wait(&status);
		}
	}

	return (1);
}
