#include "shell.h"
#include <string.h>
#include <stdio.h>

/**
 * input_parser()- parses the input
 * @buffer: the buffer
 * @delim = the delimiter
 * @argVec: the tokenized arg vector
 * Return: no return
 */

void input_parser(char *buffer, char *delim, char **argVec)
{
	int i;
	char *token;

	i = 0;
	token = strtok(buffer, delim);
	while (token != NULL)
	{
		argVec[i] = strdup(token);
		token = strtok(NULL, delim);
		i++;
	}
	argVec[i] = NULL;
}
