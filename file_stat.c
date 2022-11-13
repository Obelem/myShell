#include "shell.h"

void file_stat(char *cmd, char **argv)
{
	int i = 0;
	char *token = NULL, *key = "PATH", *path = NULL;
	char **env_cpy;
	struct stat st;

	while (environ[i])
		i++;

	env_cpy = malloc(sizeof(char *) * i);
	for (i = 0; environ[i]; i++)
		env_cpy[i] = strdup(environ[i]);
	env_cpy[i] = NULL;

	i = 0;
	while (env_cpy[i])
	{
		token = strtok(env_cpy[i++], "=");
		if (strcmp(key, token) == 0)
			break;
	}
	token = strtok(NULL, "\0");
	token = strtok(token, ":");

	while (token)
	{
		path = malloc(sizeof(char) * (strlen(token) + strlen(cmd) + 1));
		strcat(path, token), strcat(path, "/"), strcat(path, cmd);
		if (stat(path, &st) == 0)
		{
			argv[0] = strdup(path);
			exec(argv);
		}
		token = strtok(NULL, ":");
	}
	perror("not found");
	_getline();
}


