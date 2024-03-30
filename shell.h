#ifndef MAIN_H
#define MAIN_H

void prompt(void);
void input_parser(char *buffer, char *delim, char **argVec);
void free_vector(char **vector);
char *_getenv(const char *name);
char *command_path(char *command);

extern char **environ;

#endif
