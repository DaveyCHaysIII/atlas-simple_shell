#include "shell.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * input_parser()- parses the input
 * @buffer: the buffer
 * @delim : the delimiter
 * @argVec: the tokenized arg vector
 * Return: no return
 */

void input_parser(char *buffer, char *delim, char **argVec)
{
	int i;
	char *token;

	new_line_sanitize(buffer);
	i = 0;
	token = strtok(buffer, delim);
	while (token != NULL)
	{
		argVec[i] = strdup(token);
		token = strtok(NULL, delim);
		i++;
	}
	argVec[i] = NULL;
	token = NULL;
}
