#include "shell.h"

int main(int ac, char **av, char **env)
{
	char *buffer;
	ssize_t n;
	char *argVec[10];
	char *path;
	int id;

	while (1)
	{
		prompt();
		command = getline(&buffer, &n, stdin);
		input_parse(buffer, argVec);
		path = command_path(argVec[0]);
		id = fork();
		if (id == 0)
		{
			/*Child Process Handling*/
		}
		else
		{
			/*Parent Process Handling*/
		}
	}
	return (0);
}

void prompt()
{
	printf("$ :");
}
