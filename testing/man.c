#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main()
{
	char *path = "/usr/bin/ls";
	int a = access(path, F_OK);

	if (a == 0)
	{
		printf("access granted!");
	}
	else 
	{
		printf("access denied!");
	}
	return (0);
}
