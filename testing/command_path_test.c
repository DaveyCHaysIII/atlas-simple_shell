#include <stdio.h>
#include <stdlib.h>
#include "../shell.h"

int main(void)
{
	char *command = "ls";
	char *com_path = command_path(command);

	printf("we have permission to execute %s at %s\n", command, com_path);
	free(com_path);
	return (0);
}
