#include "simple_shell.h"
/**
*_which - looking for files in the current PATH
*@commands:the spliting arguments we use
*@env: envi variables.
*Return: full_path of the command or NULL if not found
*/
char *_which(char **commands, char **env)
{
	list_s *head;
	list_s *a;
	char *first = NULL;
	char *full = NULL;
	char *final = NULL;
	struct stat st;

	head = list_path(env);
	a = head;
	while (a)
	{
		first = _strcat(a->dir, "/");
		full = _strcat(first, commands[0]);
		free(first);
		if (stat(full, &st) == 0)
		{
			final = full;
			break;
		}
		free(full);
		a = a->next;
	}
	free_list(head);
	return (final);
}
