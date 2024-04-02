#include "shell.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

/**
 * command_path()- looks up command in path, determines if it has access
 * @command: the command in question
 *
 * Return: path to command on success, NULL on fail
 */

char *command_path(char *command)
{
	char *path_buffer;
	char *result;
	char **tokens;
	int i;
    int num_dirs = 1;
	char *_path = strdup(_getenv("PATH"));

    if(_path == NULL)
    {
        perror("ss: strdup_memerr ");
        return (NULL);
    }
    for (i = 0; _path[i]; i++)
    {
        if (_path[i] == ':')
        {
            num_dirs++;
        }
    }
	tokens = malloc(sizeof(char *) * num_dirs);
	if (tokens == NULL)
	{
		perror("ss: command_memerr ");
        free(_path);
		return (NULL);
	}
	input_parser(_path, ":", tokens);

    path_buffer = malloc(sizeof(char) * PATH_MAX);
    if (path_buffer == NULL)
    {
        perror("ss: path_buffer_memerr ");
        free_vector(tokens);
        return (NULL);
    }

	i = 0;
	while (tokens[i] != NULL)
	{
		strcpy(path_buffer, tokens[i]);
		strcat(path_buffer, "/");
		strcat(path_buffer, command);
		if (access(path_buffer, F_OK) == 0)
		{
			result = strdup(path_buffer);
            if (result == NULL)
            {
                perror("ss: result_memerr ");
                free(path_buffer);
			    free_vector(tokens);
			    free(_path);
			    return (NULL);
		    }
            free(path_buffer);
            free_vector(tokens);
            free(_path);
            return (result);
        }
		i++;
	}
	if (access(command, F_OK) == 0)
	{
		result = strdup(command);
        if (result == NULL)
        {
            perror("ss: result_memerr ");
            free(path_buffer);
		    free_vector(tokens);
		    free(_path);
		    return (result);
        }
	}
    free(path_buffer);
	free_vector(tokens);
	free(_path);
	perror("ss: patherr ");
	return (NULL);
}