#include "main.h"
#include <stdio.h>

/**
 * printAliases - prints the aliases.
 *
 * Return: void.
 */
void printAliases(void)
{
	int i = 0;
	int num_aliases = 0;

	while (i < num_aliases)
	{
		printf("%s='%s'\n", aliases[i].name, aliases[i].value);
		i++;
	}
}
/**
 * defineAlias - defines an alias.
 * @name: name of the alias.
 * @value: value of the alias.
 *
 * Return: void.
 */
void defineAlias(char *name, char *value)
{
	int i = 0;
	int num_aliases = 0;

	while (i < num_aliases)
	{
		if (strcmp(aliases[i].name, name) == 0)
		{
			free(aliases[i].value);
			aliases[i].value = strdup(value);
			return;
		}
		i++;
	}
	if (num_aliases < MAX_ALIASES)
	{
		aliases[num_aliases].name = strdup(name);
		aliases[num_aliases].value = strdup(value);
		num_aliases++;
	}
	else
	{
		fprintf(stderr, "Error: Maximum number of aliases reached\n");
	}
}
/**
 * processAliasCommand - processes the alias passed on a command.
 * @command: the command being passed.
 *
 * Return: void.
 */
void processAliasCommand(char *command)
{
	char *token = strtok(command, " ");
	int num_aliases = 0;

	while (token != NULL)
	{
		if (strcmp(token, "alias") == 0)
		{
			printAliases();
		}
		else
		{
			char *equal_sign = strchr(token, '=');

			if (equal_sign != NULL)
			{
				*equal_sign = '\0';
				defineAlias(token, equal_sign + 1);
			}
			else
			{
				int i = 0;

				while (i < num_aliases)
				{
					if (strcmp(aliases[i].name, token) == 0)
					{
						printf("%s='%s'\n", aliases[i].name, aliases[i].value);
						break;
					}
					i++;
				}
			}
		}
		token = strtok(NULL, " ");
	}
}

