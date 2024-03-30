#include "shell.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int ac, char **av, char **env)
{
	char *buffer;
	ssize_t n;
	char *argVec[10];
	char *path;
	int id;
	int builtin;

	while (1)
	{
		prompt();
		command = getline(&buffer, &n, stdin);
		input_parse(buffer, argVec);
		path = command_path(argVec[0]);
		if (path == NULL)
		{
			perror(""); //command not found or something
		}	
		builtin = builtin_handler(argVec[0]);
		if (path != NULL && builtin != 0)
		{
			id = fork();
			if (id == 0)
			{
				/*Child Process Handling*/
				exec_handler(path, argVec);
				//calls execve, handles all errors
			}
			else
			{
				wait(NULL);
				/*Parent Process Handling*/
			}
		}
		free_all();
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
	free_vec(argVec);
}

/**
 * builtin_handler()- handles builtins exit() and env()!
 * 
 * Return 0 if neither, 1 if either! (though exit will never make it through to completion)
 */

int builtin_handler(char *builtin)
{
	/* checks to see if buffer says exit*/
	/* checks to see if buffer says env*/
}
