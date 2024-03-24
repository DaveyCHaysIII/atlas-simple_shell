#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	/*
	 * Execve() executes based on a path and an array of arguments
	 * plus the environment (in this case NULL)
	 */
	const char *path = "/usr/bin/ls";
	char *const argVec[] = {"ls", NULL};

	execve(path, argVec, NULL);
	return (0);
}
