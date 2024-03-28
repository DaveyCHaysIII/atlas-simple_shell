#include <stdio.h>
#include "/home/davey/Desktop/showcase/atlas-simple_shell/shell.h"

int main(void)
{
	char *command = "ls";
	char *com_path = command_path(command);

	printf("we have permission to execute %s at %s\n", command, com_path);
	return (0);
}
