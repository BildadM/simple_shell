#include "main.h"

/**
 *  replaceVariables - replaces variables .
 *  @command: command to be passed.
 *
 *  Return: void.
 */
void replaceVariables(char *command)
{
	char *dollar_sign = strchr(command, '$');

	while (dollar_sign != NULL)
	{
		char *variable_name = ++dollar_sign;
		char *end_of_variable = strpbrk(variable_name, " \t\n");

		if (end_of_variable != NULL)
		{
			*end_of_variable = '\0';
		}
		if (strcmp(variable_name, "?") == 0)
		{
			int status = system(command);

			printf("%d", WEXITSTATUS(status));
		}
		else if (strcmp(variable_name, "$$") == 0)
		{
			printf("%d", getpid());
		}
		else
		{
			fprintf(stderr, "Error: Unknown variable $%s\n", variable_name);
		}
		dollar_sign = strchr(end_of_variable, '$');
	}
}
