#include "simple_shell.h"

/**
 * _getenv - to get an envi variable.
 * @name: to save the name of the envi variableon it
 * @env: environ.
 * Return: the value of the variable
 */
char *_getenv(const char *name, char **env)
{
	char *comper_to = NULL;
	int index;

	if (env == NULL)
		return (NULL);

	for (index = 0; env[index]; index++)
	{
		comper_to = strtok(env[index], "=");
		if (strcmp(comper_to, name) == 0)
		{
			return (strtok(NULL, "\n"));
		}
	}
	return (NULL);
}
