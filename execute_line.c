#include "simple_shell.h"
/**
*_execute -  executes in the main shell
*@argv: argument char-pointers array
*@commands: split arguments
*@counter: count of commands that were run
*@env: the environment
*@exit_st: exit status
*@line: buffer of getline
*/
void execute_line(char **argv, char **commands, int counter,
		  char **env, int *exit_st, char *line)
{
	pid_t pid;
	int stat;
	char *full = NULL;
	(void)line;
	pid = fork();
	if (pid < 0)
		perror("Error:");
	if (pid == 0)
	{
		full = commands[0];
		if (**commands != '/' && _strcmp(commands[0], "..") != 0)
			full = _which(commands, env);
		if (full)
		{
			if (access(full, X_OK) == 0)
				execve(full, commands, env);
		}
		_error(argv, commands[0], counter, &exit_st);
		free_loop(commands);
		free(line);
		exit(*exit_st);
	}
	else
	{
		wait(&stat);
		free_loop(commands);
		*exit_st = WEXITSTATUS(stat);
	}
}
