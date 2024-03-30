#include "shell.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(void)
{
	char *buffer;
	int command;
	size_t n;
	char **argVec;
	char *path;
	int id;
	int builtin;
	
	argVec = malloc(sizeof(char) * 100);
	while (1)
	{
		prompt();
		command = getline(&buffer, &n, stdin);
		if (command < 0)
		{
			perror("");
		}
		input_parser(buffer, " ", argVec);
		path = command_path(argVec[0]);
		if (path == NULL)
		{
			perror("");
		}	
		builtin = builtin_handler(argVec, buffer, path);
		if (path != NULL && builtin != 0)
		{
			id = fork();
			if (id == 0)
			{
				/*Child Process Handling*/
				exec_handler(path, argVec);
				continue;
			}
			else
			{
				wait(NULL);
				/*Parent Process Handling*/
			}
		}
		free_all(buffer, argVec, path);
	}
	return (0);
}

/**
 * prompt()- prints the prompt!
 *
 * Return: no return
 */

void prompt()
{
	printf("$ :");
}

/**
 * exec_handler()- handles execution of child process
 * @path: the path to the command
 * @argVec: the argument vector
 *
 * Return: no return
 */

void exec_handler(char *path, char **argVec)
{
	int exec;

	exec = execve(path, argVec, environ);
	if (exec < 0)
	{
		perror("");
	}
}

/**
 * free_all()- all will be free'd!
 * @buffer: the strdup
 * @path: the OTHER strdup
 * @argVec: the argument vector
 *
 * Return: no return
 */

void free_all(char *buffer, char **argVec, char *path)
{
	free (buffer);
	free (path);
	free_vector(argVec);
}

/**
 * builtin_handler()- handles builtins exit() and env()!
 * 
 * Return 0 if neither, 1 if either! (though exit will never make it through to completion)
 */

int builtin_handler(char **argVec, char *buffer, char *path)
{
	int builtin_num;

	builtin_num = 0;
	/* checks to see if buffer says exit*/
	if (strcmp(buffer, "exit\n") == 0)
	{
		builtin_num = 1;
		free_all(buffer, argVec, path);
		exit(0);
	}
	/* checks to see if buffer says env*/
	if (strcmp(buffer, "env\n") == 0)
	{
		builtin_num = 1;
		print_env();
	}
	return (builtin_num);

}
