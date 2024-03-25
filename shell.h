#ifndef MAIN_H
#define MAIN_H

void prompt();
void input_parser(char *buffer, char **argVec);
void free_vector(char **vector);
char *_getenv(const char *name, char **env);
char *command_path(char *command);

#endif
