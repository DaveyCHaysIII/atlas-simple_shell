#include <unistd.h>
#include <stdio.h>

int main(void)
{
	/* When you for a process, it returns
	 * zero if the process is a child 
	 * and a new pid if it is the 
	 * parent
	 */

	int pid = getpid();

	printf("My PID is %d\n", pid);

	int id = fork();
	
	printf("my ID is %d\n", id);
	return (0);
}
