#include "simple_shell.h"

/**
*Processorz - fuction invoked for a signal function and show the prompt
*@sig: number of the signal
*/

void Processorz(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n($) ", 5);
}

/**
*main - where the program is start
*@argc: argument count
*@argv: argument value
*@env: the environment of the code
*Return: 0
*/

int main(int argc, char **argv, char **env)
{
	char *lines = NULL;
	char **shell_commands;
	size_t bufsize = 0;
	ssize_t line_length = 0, counter = 0;
	int exit_st = 0;
	(void)argc;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(1, "($) ", 4);
		signal(SIGINT, Processorz);
		line_length = getline(&lines, &bufsize, stdin);
		counter++;
		if (special_case(lines, line_length, &exit_st) == 3)
			continue;
		shell_commands = split_line(lines);
		if (_strcmp("exit", *shell_commands) == 0)
			built_in_exit(lines, shell_commands, &exit_st, counter);
		else if (_strcmp("env", *shell_commands) == 0)
			built_in_env(shell_commands, env, &exit_st);
		else
			execute_line(argv, shell_commands, counter, env, &exit_st, lines);
		fflush(stdin);
	}
	free(lines);
	return (0);
}
