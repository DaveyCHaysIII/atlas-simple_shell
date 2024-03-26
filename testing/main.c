#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "/home/davey/Desktop/showcase/atlas-simple_shell/shell.h"

int main()
{
	int i;
	char *string = getenv("PATH");
	char **argVec;

	argVec = malloc(sizeof(char) * 100);

	input_parser(string, argVec);
	
	i = 0;
	while (argVec[i] != NULL)
	{
		printf("%s\n", argVec[i]);
		i++;
	}
	free_vector(argVec);
	return (0);
}
