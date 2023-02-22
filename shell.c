#include "shell.h"

/**
 * main - simple UNIX shell prompt \n
 *
 * @argc: count of arguments to main
 * @argv: pointer to an array of string args
 * @env: null-terminated array of strings
 *
 * Return: exit code 0 on success, and non-zero status codes on fail
 */
int main(int argc, char **argv, char **env)
{
	char **args, *line;
	int status = 1;
	(void) argc;

	while (status)
	{
		printf("#cisfun$ ");
		line = read_line();
		args = split_line(line);
		status = execute_command(args);

		/* built-in environment */
		if (strcmp(argv[0], "env") == 0)
		{
			while (*env)
			{
				printf("%s\n", *env++);
			}
			return (1);
		}

		free(line);
		free(args);
	}

	return (0);
}
