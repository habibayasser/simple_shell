#include "simple_shell.h"
/**
*special_case - function that adjust special cases such as:
*EOF
*@line: stores the stdin input
*@line_len: count the line length
*@exit_st: to exit from statue
*Return: 0 if the entry does not match any special case
*or 3 if it is a \n
*/
int special_case(char *line, ssize_t line_len, int *exit_st)
{
	int index = 0;
	int length = 0;

	if (line_len == -1 && isatty(STDIN_FILENO) == 1)
	{
		write(1, "\n", 1);
		free(line);
		exit(*exit_st);
	}
	if (line_len == -1 && isatty(STDIN_FILENO) == 0)
	{
		free(line);
		exit(*exit_st);
	}
	if (_strcmp(line, "\n") == 0)
	{
		*exit_st = 0;
		return (3);
	}
	length = _strlen(line);
	while (index < length - 2)
	{
		if (line[index] != ' ' && line[index] != '\t')
			return (0);
		++index;
	}
	*exit_st = 0;
	if (line[0] == '/')
		return (0);
	return (3);
}
