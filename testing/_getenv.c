#include <stdio.h>
#include <unistd.h>
#include "/home/davey/Desktop/showcase/atlas-simple_shell/shell.h"


int main(void)
{
	printf("%s\n", _getenv("PWD"));
	return (0);
}	

