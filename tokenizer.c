#include "main.h"

/**
 * tokenizer - entry point
 * description - splits the commandline arguments into tokens
 * @command: The character to print
 * Return: Always 0 (Success)
 */
char **tokenizer(char *command)
{
	size_t command_size = 0;
	int i;
	char *token, **arr;

	token = strtok(command, " \n");
	arr = malloc(sizeof(char *) * command_size);

	arr[0] = token;

	for (i = 1; token != NULL; i++)
	{
		token = strtok(NULL, " \n");
		arr[i] = token;
	}
	return (arr);
}
