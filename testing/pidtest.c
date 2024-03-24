#include <unistd.h>
#include <stdio.h>

int main(void)
{
	/*
	 * pid's exist for both parent and 
	 * child processes
	 */

	int ppid = getppid();
	fork();
	
	printf("my ID is %d", ppid);
	return (0);
}
