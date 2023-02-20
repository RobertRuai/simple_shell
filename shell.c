#include "main.h"
#define MAX_COMMAND_LENGTH 1024

/**
 * main - shell prompt \n
 * Description - program that carries out prompt, read, and execute shell funcions
 * @ac - character to print
 * @argv - character to print
 * @env - character to print
 * Return: exit code 0 on success, and non-zero status codes on fail
 */
int main(int ac, char **argv, char **env)
{
	char *command = NULL;
	size_t command_size = 0;
	int  i, j;
	char *token;
	(void) ac;

	while (1)
	{
		printf("#cisfun$ ");
		fflush(stdout);

		if (getline(&command, &command_size, stdin) == -1)
		{
			perror("getline");
			exit(1);
		}
		token = strtok(command, " \n");
		argv = malloc(sizeof(char *) * command_size);

		argv[0] = token;
		if (strcmp(argv[0], "exit") == 0)
			exit(0);

		for (i = 1; token != NULL; i++)
		{
			token = strtok(NULL, " \n");
			argv[i] = token;
		}
		/* rm newline character from input */
		command[strcspn(command, "\n")] = '\0';
		_execute(command, argv);
	}
	free(command);
	return (0);
}
