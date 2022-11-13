#include "shell.h"

void exec(char **argv)
{
	int i;

	if (fork() == 0)
	{
		if (execve(argv[0], argv, environ) == -1)
			perror("");
	}
	else
	{
		wait(NULL);
		_getline();
	}
}
