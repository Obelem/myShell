#include "shell.h"

char **tokenizer(char *cmd)
{
    char *cmdcpy = NULL, *token = NULL;
	char **argv = NULL;
    int argc = 0, i = 0;
    struct stat st;

	cmdcpy = malloc(sizeof(char) * strlen(cmd));

	strcpy(cmdcpy, cmd);

	token = strtok(cmd, " \n");

	/* get number of arguments ==> argc */
	while (token)
		token = strtok(NULL, " \n"), argc++;

	argv = malloc(sizeof(char *) * argc);

	/* insert strings in string array */
	token = strtok(cmdcpy, " \n");
	while (token)
	{
		argv[i] = malloc(sizeof(char) * strlen(token));
		strcpy(argv[i++], token);
		token = strtok(NULL, " \n");
	}
	argv[i] = NULL;
    if (argv[0][0] == '/' && stat(cmd, &st) == 0)
        exec(argv);

    file_stat(argv[0], argv);
}
