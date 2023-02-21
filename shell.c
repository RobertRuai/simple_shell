#include "main.h"
#define MAX_COMMAND_LENGTH 1024

/**
 * main - shell prompt \n
 * Description - program that carries out prompt,read,execute shell funcions
 * @ac:  argument count
 * @argv: argument vector array pointer
 * @env: environment variable array pointer
 * Return: exit code 0 on success, and non-zero status codes on fail
 */
int main(int ac, char **argv, char **env)
{
	char *command = NULL;
	size_t command_size = 0;
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
		argv = tokenizer(command);
		if (strcmp(argv[0], "exit") == 0)
			exit(0);
		/* environment variables */
		if (strcmp(argv[0], "env") == 0)
		{
			while (*env)
			{
				printf("%s\n", *env++);
			}
			return (1);
		}
		command[strcspn(command, "\n")] = '\0';
		_execute(command, argv);
	}
	free(command);
	return (0);
}
