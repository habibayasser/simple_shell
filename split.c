#include "simple_shell.h"
/**
*split_line - make double pointers array that holds pointers
*to each string from the command line
*@line:  stores the stdin input
*Return: double pointer array of pointers that are commands to interpret
*
*/
char **split_line(char *line)
{
	int index = 0;
	char *tokeniz;
	char *token_hashTable;
	char **word_arr;
	int length;

	length = _strlen(line);

	word_arr = malloc(sizeof(char *) * (length + 1));
	if (word_arr == NULL)
		return (NULL);
	token_hashTable = strtok(line, "#");
	tokeniz = strtok(token_hashTable, TOK_DELIM);
	while (tokeniz != NULL)
	{
		word_arr[index] = malloc(_strlen(tokeniz) + 1);
		if (word_arr[index] == NULL)
		{
			free_loop(word_arr);
			return (NULL);
		}
		_strncpy(word_arr[index], tokeniz, _strlen(tokeniz) + 1);
		tokeniz = strtok(NULL, TOK_DELIM);
		index++;
	}
	word_arr[index] = NULL;
	return (word_arr);
}
