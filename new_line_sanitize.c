#include "shell.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

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