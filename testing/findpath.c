#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	char *buff;
	ssize_t n;
	char *argVec[] = {NULL};
	char *path = "/usr/bin/";
	
	ssize_t command = getline(&buff, &n, stdin);
	strtok()
	return (0);
}
