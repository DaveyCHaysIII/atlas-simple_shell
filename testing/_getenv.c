#include <stdio.h>
#include <unistd.h>
#include "../shell.h"


int main(void)
{
	printf("%s\n", _getenv("PWD"));
	return (0);
}	

