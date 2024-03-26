#include "shell.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/*
 * _getenv()- gets a specific environment variable
 * @name: name of variable desired
 * @env: the environ array
 *
 * Return: the value on success, NULL on fail
 */

char *_getenv(const char *name, char **env)
{
	int i, j;
	int status;

	for (i = 0; env[i] != NULL; i++)
	{
    		status = 1;
		for (j = 0; env[i][j] != '='; j++)
		{
			if (name[j] != env[i][j])
			{
				status = 0;
				break;
			}
		}
		if (status)
		{
			return (&env[i][j + 1]);
		}
	}
	return (NULL);
}

/*
 * free_vector()- frees an array of characters
 * @vector: the array in question
 *
 * Return: no return
 */

void free_vector(char **vector)
{
	int i;

	i = 0;
	while (vector[i] != NULL)
	{
		free(vector[i]);
		printf("freed vector[%d]\n", i);
		i++;
	}
	free(vector);
}


