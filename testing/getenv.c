#include <stdio.h>

char *_getenv(const char *name);

int main(void)
{
	printf("path = %s\n", _getenv("PATH"));
}

char *_getenv(const char *name)
{
	extern char **environ;
        int i, j;
        int status;

        for (i = 0; environ[i] != NULL; i++)
        {
                status = 1;
                for (j = 0; environ[i][j] != '='; j++)
                {
                        if (name[j] != environ[i][j])
                        {
                                status = 0;
                                break;
                        }
                }
                if (status)
                {
                        return (&environ[i][j + 1]);
                }
        }
        return (NULL);
}

