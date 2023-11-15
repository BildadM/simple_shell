#include "main.h"
#include <stdbool.h>

#define MAX_ARGS 100

/**
 * tokenizeInput - splits strings using the space.
 * @input: command
 * @args: argument passed.
 *
 * Return: void.
 */
void tokenizeInput(char *input, char **args)
{
	int i = 0;
	char *token = input;

	while (*input != '\0')
	{
		if (*input == ' ' || *input == '\t' || *input == '\n')
		{
			*input = '\0';
			args[i] = token;
			i++;
			token = input + 1;
		}
		input++;
	}
	args[i] = token;
	args[i + 1] = NULL;
}
