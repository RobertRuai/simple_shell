#include "shell.h"

/**
 * read_line - read a characters(line) from stdin
 *
 * Return: commands from user's command line
 */
char *read_line(void)
{
	char *line = NULL;
	size_t buf_size = 0;

	if (getline(&line, &buf_size, stdin) == -1)
	{
		perror("getline");
		exit(1);
	}

	return (line);
}
