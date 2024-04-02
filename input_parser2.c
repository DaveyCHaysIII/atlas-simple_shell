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
	whitespace_handler(buffer);
	i = 0;
	token = strtok(buffer, delim);
	while (token != NULL)
	{
        if (i >= 10)
        {
            fprintf(stderr, "Too many args\n");
            break;
        }
		argVec[i] = strdup(token);
        if (argVec[i] == NULL)
        {
            perror("Failed to duplicate token");
            break;
        }
		token = strtok(NULL, delim);
		i++;
	}
	argVec[i] = NULL;
	token = NULL;
}