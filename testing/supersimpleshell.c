#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int main(int ac, char **av)
{
        /* variables for getline() */
        ssize_t n;
        char *buff;
        /* variables for counting */
        int i, j;
        /* id variable */
        int id;
        /* variables for execve*/
        char *argVec[] = {NULL, NULL};
        char *envVec[] = {NULL};
        char *cmd = "/usr/bin/ls";
        /* variables for strtok()*/
        char *token;
        char *delim = " ";

	
        buff = NULL;
        j = 1;
        n = 0;
        while (j == 1)
        {
                /* setup prompt & environment */
                printf("$: ");
                ssize_t command = getline(&buff, &n, stdin);

		id = fork();

                /* child process handler */
                if (id == 0)
                {
                        /* preparing buffers for command execution */
                        i = 0;
                        token = strtok(buff, delim);
                        while (token != NULL)
                        {
                                argVec[i] = strdup(token);
                                token = strtok(NULL, delim);
                        }
                        /* see if we can exectute command */
                        if (strcmp(argVec[0], "ls\n") == 0)
                        {
                                if (execve(cmd, argVec, NULL) == -1)
                                {
                                        perror("exec failed :(");
                                }
                        }
                        /* default behavior */
                        else
                        {
                                printf("%s", argVec[0]);
                                //while (i >= 0)
                                //{
                                //      free(argVec[i]);
                                //}
                        }
			/* this kills the child */
			j++;
                }
                /* parent process handler */
                else
                {
                        wait(NULL);
			int comp = strcmp(buff, "exit\n");
                        if (comp == 0)
                        {
                                free(buff);
                                j++;
                        }
                }
        }
        return (0);
}

