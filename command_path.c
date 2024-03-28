#include "shell.h"
#include <string.h>
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
	int i;

	char *path = _getenv("PATH");
	printf("got path!");

	tokens = NULL;
	input_parser(path, ":", tokens);
	printf("parsed tokens!");
	i = 0;
	while (tokens[i] != NULL)
	{
		strcpy(path_buffer, tokens[i]);
		strcat(path_buffer, command);
		printf("Buffer: %s\n", path_buffer);
		if (access(path_buffer, F_OK) == 0 && access(path_buffer, X_OK) == 0)
		{
			free_vector(tokens);
			result = strdup(path_buffer);
			return (result);
		}
		i++;
	}
	free_vector(tokens);
	return (NULL);
}
