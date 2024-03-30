#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	access("/usr/bin/foo", F_OK);
	perror("this is a test: ");
	return (0);
}
