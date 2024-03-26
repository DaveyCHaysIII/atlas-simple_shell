#include "shell.h"
#include <string.h>
#include <stdio.h>

/*
 * input_parcer()- parses the input
 * @buff: the buffer to be parsed
 * @argVec: pointer to the null-terminated array holding parse
 * Return: no return
 */

void input_parser(char *buffer, char **argVec)
{
	int i;
	char *token;
	char *delim = ":";

	i = 0;
	token = strtok(buffer, delim);
	while (token != NULL)
	{
		printf("%s\n", token);
		argVec[i] = strdup(token);
		token = strtok(NULL, delim);
		i++;
	}
	argVec[i] = NULL;
}
