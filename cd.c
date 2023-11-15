#include "main.h"

/**
 * changeDirectory - changes current directory.
 * @args: argument passed.
 *
 * Return: void.
 */
void changeDirectory(char **args)
{
	char cwd[1024];
	char oldpwd[1024];

	getcwd(cwd, sizeof(cwd));

	if (args[1] == NULL)
	{
	chdir(getenv("HOME"));
	}
	else if (strcmp(args[1], "-") == 0)
	{
		chdir(getenv("OLDPWD"));
	}
	else
	{
		chdir(args[1]);
	}

	setenv("OLDPWD", cwd, 1);
	getcwd(oldpwd, sizeof(oldpwd));
	setenv("PWD", oldpwd, 1);
}

