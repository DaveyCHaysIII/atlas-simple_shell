#include <stdio.h>
#include <unistd.h>

char *_getenv(const char *name, char **env);

int main(int ac, char **av, char **env)
{
	printf("%s\n", _getenv("PWD", env));
	return (0);
}	

char *_getenv(const char *name, char **env)
{
    int i, j;
    int status;

for (i = 0; env[i] != NULL; i++)
{
    status = 1;
    for (j = 0; env[i][j] != '='; j++)
    {
        if (name[j] != env[i][j])
        {
            status = 0;
            break;
        }
    }

    if (status)
    {
        return (&env[i][j + 1]);
    }
}
return (NULL);
}

