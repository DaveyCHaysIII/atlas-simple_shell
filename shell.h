#ifndef MAIN_H
#define MAIN_H

void prompt(void);
void input_parser(char *buffer, char *delim, char **argVec);
void free_vector(char **vector);
void exec_handler(char *path, char **argVec);
void free_all(char *buffer, char **argVec, char *path);
void print_env();
int builtin_handler(char **argVec, char *buffer, char *path);
char *_getenv(const char *name);
char *command_path(char *command);

extern char **environ;

#endif
