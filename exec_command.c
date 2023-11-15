#include "main.h"
#include <stdio.h>
#include <sys/wait.h>

/**
 * executeCommand - executes commands passed to the shell.
 * @command: argument passed.
 * @args: arguments
 * @path: path of the command.
 *
 * Return: void.
 */
void executeCommand(char *command, char **args, char *path)
{pid_t pid;
	int status;
	char f_path[100];

	replaceVariables(command);
	if (strcmp(command, "/bin/ls") == 0)
	{pid = fork();
		if (pid == 0)
		{
			if (execv(command, args) == -1)
			{perror("/bin/ls");
				exit(EXIT_FAILURE);
			}
		}
		else if (pid < 0)
		{perror("Fork failed");
			exit(EXIT_FAILURE);
		}
		else
		{waitpid(pid, &status, 0);
		}
	}
	else
	{strcpy(f_path, path);
		strcat(f_path, args[0]);
		pid = fork();
		if (pid == 0)
		{
			if (execv(f_path, args) == -1)
			{perror("shell");
				exit(EXIT_FAILURE);
			}
		}
		else if (pid < 0)
		{perror("Fork failed");
			exit(EXIT_FAILURE);
		}
		else
		{waitpid(pid, &status, 0);
		}
	}
}

