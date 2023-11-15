#include "main.h"
#include <stdio.h>

/**
 * printEnvironment - prints the current environment.
 *
 * Return: void
 */
void printEnvironment(void)
{
	char **env = environ;

	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
}
