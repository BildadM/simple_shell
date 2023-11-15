#include "main.h"
#include <stdio.h>

/**
 * main - main file.
 * @argc: argument count.
 * @argv: argument vector.
 *
 * Return: always success.
 */
int main(int argc, char *argv[])
{
	char *lineptr = NULL;
	size_t n = 0;
	char *commandl = ":) ";
	ssize_t input;
	char *path = "/bin/";
	bool exit_shell = false;
	char *command;
	int i = 1;
	bool interactive = (argc == 1);

	if (argc > 2)
	{
		fprintf(stderr, "Usage: %s [filename]\n", argv[0]);
		return (EXIT_FAILURE);
	}
	if (!interactive)
	{
		FILE *file = fopen(argv[1], "r");

		if (file == NULL)
		{
			perror("Error opening file");
			return (EXIT_FAILURE);
		}
	}
	while (!exit_shell)
	{
		printf("%s", commandl);
		input = getline(&lineptr, &n, stdin);
		if (input == -1)
		{
			printf("Leaving...\n");
			break;
		}
		if (input > 0 && lineptr[input - 1] == '\n')
		{
			lineptr[input - 1] = '\0';
		}
		command = strtok(lineptr, " ");
		argv[0] = command;
		while ((argv[i] = strtok(NULL, " ")) != NULL)
		{
			i++;
		}
		if (lineptr[0] != '\0' && lineptr[0] != '#')
		{
			if (strncmp(lineptr, "exit", 4) == 0)
			{
				char *status_str = strtok(command + 5, " ");

				if (status_str != NULL)
				{
					int status = atoi(status_str);

					exit(status);
				}
				else
				{
					exit(EXIT_SUCCESS);
				}
			}
			else if (strncmp(lineptr, "alias", 5) == 0)
			{
				processAliasCommand(lineptr + 5);
			}
			else
			{
				executeCommand(lineptr, argv, path);
			}
		}
	}
	free(lineptr);
	return (0);
}
