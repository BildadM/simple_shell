#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>

#define MAX_ALIASES 100
/**
 * struct Alias - start of alias
 * @name: name
 * @value: value
 *
 */
struct Alias
{
	char *name;
	char *value;
};

struct Alias aliases[MAX_ALIASES];

void printAliases(void);
void defineAlias(char *name, char *value);
void processAliasCommand(char *command);
void executechar(char *command, char **args, char *path);
char *customGetline();
int setenvironment(char **args);
int unsetenvironment(char **args);
void execute_command(char *command);
void handleCommand(char *command);
void replaceVariables(char *command);
void changeDirectory(char **args);
extern char **environ;

#endif
