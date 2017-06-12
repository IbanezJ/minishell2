/*
** forking.c for minishell in /home/ibanez_j/PSU_2016_minishell1
** 
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
** 
** Started on  Fri Jan 13 21:40:08 2017 Jean-Alexandre IBANEZ
** Last update Thu Apr 20 22:43:42 2017 Jean-Alexandre IBANEZ
*/

#include <string.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include "my.h"

void	display_error(int status)
{
  int	error;

  error = 0;
  waitpid(-1, &status, 0);
  if (WIFSIGNALED(status))
    {
      error = WTERMSIG(status);
      if (error == 11 && !(WCOREDUMP(status)))
	my_printf("Segmentation fault\n");
      else if (error == 8 && !(WCOREDUMP(status)))
	my_printf("Floating exception\n");
      else if (error == 11 && WCOREDUMP(status))
	my_printf("Segmentation fault (core dumped)\n");
      else if (error == 8 && WCOREDUMP(status))
	my_printf("Floating exception (core dumped)\n");
      else if (error == 6 && WCOREDUMP(status))
	my_printf("Abort (core dumped)\n");
    }
  if (status == 11 || status == 139)
    status = 139;
  else if (status == 8 || status == 136)
    status = 136;
  else if (status != 0)
    status = 1;
  g_exit_value = status;
}

void	forking(char **newargv, char **env)
{
  pid_t	id;
  int	status;

  status = 1;
  id = fork();
  if (id != -1)
    {
      if (id == 0)
	{
	  if (execve(newargv[0], newargv, env) == -1)
	    {
	      if (errno == ENOEXEC)
		my_printf("%s: Exec format error."
			  " Binary file not executable.\n", newargv[0]);
	      else
		my_printf("%s: %s.\n", newargv[0], strerror(errno));
	    }
	  kill(getpid(), SIGTERM);
	}
      else
	display_error(status);
    }
  else
    perror("fork");
}
