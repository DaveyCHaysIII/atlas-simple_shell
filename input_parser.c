#include "shell.h"
#include <string.h>

/*
 * input_parcer()- parses the input
 * @buff: the buffer to be parsed
 * @argVec: pointer to the null-terminated array holding parse
 * Return: no return
 */

void input_parcer(char *buffer, char **argVec)
{
	int i;
	char *token;
	const char *delim = " ";

	i = 0;
	token = strtok(buff, delim);
	while (token != NULL)
	{
		argVec[i] = strdup(token);
		token = strtok(NULL, delim);
		i++;
	}
}
