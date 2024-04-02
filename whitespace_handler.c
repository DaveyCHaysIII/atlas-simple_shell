#include "shell.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

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