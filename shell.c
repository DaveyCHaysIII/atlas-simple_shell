#include "shell.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

/**
 * main()- Simple Shell
 *
 * Return: 0
 */

int main(void)
{
	char *buffer;
	int command;
	size_t n;
	char **argVec;
	char *_path;
	int id;
	int builtin;

	while (1)
	{
		n = 0;
		command = 0;
		buffer = NULL;
		_path = NULL;
		argVec = malloc(sizeof(char *) * 10);
		prompt();
		command = getline(&buffer, &n, stdin);
		if (command < 0)
		{
			perror("ss: commanderr ");
		}
		input_parser(buffer, " ", argVec);
		_path = command_path(argVec[0]);
		builtin = builtin_handler(argVec, buffer, _path);
		if (_path != NULL && builtin == 0)
		{
			id = fork();
			if (id == 0)
			{
				exec_handler(_path, argVec, buffer);
				continue;
			}
			else
			{
				wait(NULL);
				free_all(buffer, argVec, _path);
				continue;
			}
		}
		free_all(buffer, argVec, _path);
	}
	printf("something went horribly wrong");
	return (0);
}

/**
 * prompt()- prints the prompt!
 *
 * Return: no return
 */

void prompt(void)
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

void exec_handler(char *_path, char **argVec, char *buffer)
{
	int exec;

	exec = execve(_path, argVec, environ);
	if (exec < 0)
	{
		perror("ss: execerr ");
	}
	free_all(buffer, argVec, _path);
}

/**
 * free_all()- all will be free'd!
 * @buffer: the strdup
 * @path: the OTHER strdup
 * @argVec: the argument vector
 *
 * Return: no return
 */

void free_all(char *buffer, char **argVec, char *_path)
{
	free(buffer);
	free(_path);
	free_vector(argVec);
}

/**
 * builtin_handler()- handles builtins exit() and env()!
 * @argVec: the argument vector
 * @buffer: the buffer
 * @path: the path
 *
 * Return: 0 if neither, 1 if either!
 */

int builtin_handler(char **argVec, char *buffer, char *_path)
{
	int builtin_num;

	builtin_num = 0;
	/* checks to see if buffer says exit*/
	if (strcmp(buffer, "exit") == 0)
	{
		builtin_num = 1;
		free_all(buffer, argVec, _path);
		exit(0);
	}
	/* checks to see if buffer says env*/
	if (strcmp(buffer, "env") == 0)
	{
		builtin_num = 1;
		print_env();
	}
	return (builtin_num);

}
