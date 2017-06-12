/*
** execution.c for minishell2 in /home/ibanez_j/PSU_2016_minishell2
** 
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
** 
** Started on  Tue Apr  4 20:54:41 2017 Jean-Alexandre IBANEZ
** Last update Sat Apr  8 14:49:09 2017 Jean-Alexandre IBANEZ
*/

#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

void	exec_commande(char *path, char *s, char ***envp)
{
  char	**newpath;
  char	**newarg;

  newpath = put_in_tab(path, ':');
  newarg = put_in_tab(s, ' ');
  if (my_strcmp(newarg[0], "cd") == 0 && newarg[1])
    {
      if (my_strcmp(newarg[1], "-") == 0)
	my_cd_back(envp);
      else if ((my_cd(newarg[1], envp)) == -1 && (g_exit_value = 1))
	my_printf("%s: %s.\n", newarg[1], strerror(errno));
    }
  else if (my_strcmp(newarg[0], "cd") == 0)
    my_cd("null", envp);
  else if (access(newarg[0], X_OK) == 0)
    forking(newarg, (*envp));
  else if ((newarg[0] = find_command(newpath, newarg[0])) != NULL)
    forking(newarg, (*envp));
  else
    {
      printf_before_space(s);
      g_exit_value = 1;
    }
  free_tab(newarg);
  free_tab(newpath);
}

void	choose_exec(char *s, char **newarg, char ***newenv, char *path)
{
  if (my_strcmp(newarg[0], "exit") == 0)
    free_func(s, path, newarg, *newenv);
  else if (my_strcmp(newarg[0], "env") == 0)
    display_env(*newenv);
  else if (my_strcmp(newarg[0], "setenv") == 0 && newarg[1] &&
	   newarg[2] && newarg[3] && (g_exit_value = 1))
    my_printf("setenv: Too many arguments.\n");
  else if (my_strcmp(newarg[0], "setenv") == 0 && newarg[1] && newarg[2])
    (*newenv) = my_setenv((*newenv), newarg[1], newarg[2]);
  else if (my_strcmp(newarg[0], "setenv") == 0 && newarg[1])
    (*newenv) = my_setenv_only_one((*newenv), newarg[1]);
  else if (my_strcmp(newarg[0], "setenv") == 0)
    display_env(*newenv);
  else if (my_strcmp(newarg[0], "unsetenv") == 0 && newarg[1])
    (*newenv) = my_unsetenv((*newenv), newarg + 1);
  else if (my_strcmp(newarg[0], "unsetenv") == 0)
    {
      my_printf("unsetenv: Too few arguments.\n");
      g_exit_value = 1;
    }
  else
    exec_commande(path, s, newenv);
  free_tab(newarg);
  free(s);
}

void	exec_all(char **new_command, char ***newenv, char *path)
{
  int	i;
  char	**newarg;

  i = 0;
  while (new_command[i] != NULL)
    {
      if (is_there_pipe(new_command[i]) == 1)
	my_pipe(new_command[i], newarg, newenv, path);
      else
	choose_exec(new_command[i], (newarg = put_in_tab(new_command[i], ' ')),
		    newenv, path);
      i++;
    }
}
