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
		argVec[i] = strdup(token);
		token = strtok(NULL, delim);
		i++;
	}
	argVec[i] = NULL;
	token = NULL;
}


/**
 * new_line_sanitize()- removes new line from buffer prior to tokenization
 * @buffer: the buffer in question
 *
 * Return: no return
 */

void new_line_sanitize(char *buffer)
{
	int i;

	if (strlen(buffer) > 2)
	{
		i = 0;
		while (buffer[i] != '\0')
		{
			if (buffer[i] == '\n')
			{
				buffer[i] = '\0';
			}
			i++;
		}
	}
}

/**
 * whitespace_handler()- handles whitespace only entries
 * @buffer: the buffer in question
 *
 * Return: no return
 */

void whitespace_handler(char *buffer)
{
	int i, whitespace_count;

	i = 0;
	whitespace_count = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == ' ')
		{
			whitespace_count++;
		}
		i++;
	}
	if (i == whitespace_count)
		buffer[0] = '\0';
}
