#include <stdio.h>
#include <string.h>

int main(int ac, char **av, char **env)
{
	int i;

	i = 0;
	while (env[i] != NULL)
	{
		if (strstr(env[i], "PATH") != NULL)
		{
			printf("%s\n", env[i]);
		}
		i++;
	}
	return (0);
}
