#include "simple_shell.h"
#include <ctype.h>
#include <string.h>
/**
*is_positive - function that check if a string is a positive number
*@comper: string to check
*Return: 0 on success and -1 if is negative or is not a number
*/
int is_positive(char *comper)
{
	int index = 0;

	if (comper[0] == '-')
		return (-1);
	for (index = 0; comper[index]; index++)
	{
		if (comper[index] < 48 || comper[index] > 57)
			return (-1);
	}
	return (0);
}
/**
*_atoi - transform a char in an integer
*@comper: string to check
*Return: the integer
*/
int _atoi(char *comper)
{
	int num = 0, the_sign = 1, result = 0;

	for (num = result = 0; comper[num]; num++)
	{
		if (comper[num] == '-')
			the_sign *= -1;
		if (comper[num] >= '0' && comper[num] <= '9')
			result = 10 * result - (comper[num] - '0');
		if (result < 0 && (comper[num] < '0' || comper[num] > '9'))
			break;
	}
	if (the_sign > 0)
		result *= -1;
	return (result);
}
/**
*built_in_exit - implement the exit builtin
*@line: stors the command to be splited
*@commands: the split arguments
*@exit_st: the exit status
*@counter: count of lines
*/
void built_in_exit(char *line, char **commands, int *exit_st, int counter)
{
	int number = 0;

	if (commands[1])
	{
		if (is_positive(commands[1]) == 0)
		{
			number = _atoi(commands[1]);
			*exit_st = number;
		}
		else
		{
			write(1, "./hsh: ", 7);
			print_num(counter);
			write(1, ": ", 2);
			write(1, "exit: Illegal number: ", 22);
			write(1, commands[1], _strlen(commands[1]));
			write(1, "\n", 1);
			*exit_st = 2;
			free_loop(commands);
			return;
		}
	}
	free_loop(commands);
	free(line);
	exit(*exit_st);
}
/**
*built_in_env - implement the env builtin
*@commands: the split arguments
*@env: the environment
*@exit_st: the exit status
*/
void built_in_env(char **commands, char **env, int *exit_st)
{
	char **a = env;

	while (*a != NULL)
	{
		write(1, *a, _strlen(*a));
		write(1, "\n", 1);
		a++;
	}
	*exit_st = 0;
	free_loop(commands);
}
