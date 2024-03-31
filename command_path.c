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
	int i;
	char *_path = strdup(_getenv("PATH"));

	tokens = malloc(sizeof(char) * 100);
	if (tokens == NULL)
	{
		perror("ss: command_memerr ");
		return (NULL);
	}
	input_parser(_path, ":", tokens);

	i = 0;
	while (tokens[i] != NULL)
	{
		strcpy(path_buffer, tokens[i]);
		strcat(path_buffer, "/");
		strcat(path_buffer, command);
		if (access(path_buffer, F_OK) == 0) 
		{
			/** TODO: pull out into separate func */
			result = strdup(path_buffer);
			free_vector(tokens);
			return (result);
		}
		i++;
	}
	command[strlen(command)-1] = '\0';
	if (access(command, F_OK) == 0)
	{
		/** TODO: pull out into separate func */
		result = strdup(command);
		free_vector(tokens);
		return (result);
	}
	free_vector(tokens);
	perror("ss: patherr ");
	return (NULL);
}
