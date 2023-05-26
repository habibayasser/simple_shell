#include "simple_shell.h"
/**
*_werror - puts a char to the std error
*@c: character to write
*Return: int to print
*/
int _werror(char c)
{
	return (write(STDERR_FILENO, &c, 1));
}
/**
*print_num -  print a num with function write
*@counter: the number of times you have done a command
*/
void print_num(int counter)
{
	int length = 1, powerten = 1, counter2;

	counter2 = counter;

	while (counter2 >= 10)
	{
		counter2 /= 10;
		powerten *= 10;
		++length;
	}
	while (length >= 1)
	{
		if ((counter / powerten) < 10)
			_werror(counter / powerten + '0');
		else
			_werror(((counter / powerten) % 10 + '0'));
		--length;
		powerten /= 10;
	}
}
/**
*_error - writes an error message similar to the sh error
*when command not found
*@argv: the argv from the main function
*@first: first command to print if not found
*@count: the number of times you have done a command
*@exit_st: exit status
*/
void _error(char **argv, char *first, int count, int **exit_st)
{
	struct stat st;

	write(STDERR_FILENO, argv[0], _strlen(argv[0]));
	write(STDERR_FILENO, ":", 2);
	print_num(count);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, first, _strlen(first));
	write(STDERR_FILENO, ": ", 2);
	if (stat(first, &st) == 0 && S_ISDIR(st.st_mode))
	{
		**exit_st = 126;
		if (_strcmp(first, "..") == 0)
			**exit_st = 127;
		perror("");
	}
	else
	{
		**exit_st = 127;
		write(STDERR_FILENO, "not found\n", 10);
	}
}
