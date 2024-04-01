#ifndef MAIN_H
#define MAIN_H

void prompt(void);
void input_parser(char *buffer, char *delim, char **argVec);
void new_line_sanitize(char *buffer);
void whitespace_handler(char *buffer);
void free_vector(char **vector);
void exec_handler(char *path, char **argVec, char *buffer);
void free_all(char *buffer, char **argVec, char *path);
void print_env(void);
int builtin_handler(char **argVec, char *buffer, char *path);
char *_getenv(const char *name);
char *command_path(char *command);

extern char **environ;

#endif
