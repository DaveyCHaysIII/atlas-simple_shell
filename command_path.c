#include "shell.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

/**
 * command_path()- looks up command in path, determines if it has access
 * @command: the command in question
 *
 * Return: path to command on success, NULL on fail
 */

char *command_path(char *command)
{
	char path_buffer[255];
	char *result;
	char **tokens;
	int i, j, k;

	char *path = _getenv("PATH");

	tokens = malloc(sizeof(char) * 100);
	if (tokens == NULL)
	{
		perror("ss: command_memerr ");
		return (NULL);
	}
	input_parser(path, ":", tokens);

	k = 0;
	while (tokens[k] != NULL)
	{
		printf("tokens[%d] = %s\n", k, tokens[k]);
		k++;
	}

	i = 0;
	while (tokens[i] != NULL)
	{
		strcpy(path_buffer, tokens[i]);
		strcat(path_buffer, "/");
		strcat(path_buffer, command);
		j = 0;
		while (path_buffer[j] != '\0')
		{
			if (path_buffer[j] == '\n')
			path_buffer[j] = '\0';
			j++;
		}
		if (access(path_buffer, F_OK) == 0)
		{
			result = strdup(path_buffer);
			free_vector(tokens);
			return (result);
		}
		i++;
	}
	free_vector(tokens);
	perror("ss: patherr ");
	return (NULL);
}
