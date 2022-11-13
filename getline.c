#include "shell.h"


char *_getline()
{
    char *cmd = NULL;
	size_t n;

    printf("Type in here: ");
    if (getline(&cmd, &n, stdin) == -1)
        exit(0);
    tokenizer(cmd);
}
