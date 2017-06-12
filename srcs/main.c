/*
** main.c for minishel in /home/ibanez_j/PSU_2016_minishell1
** 
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
** 
** Started on  Sun Jan  8 15:18:24 2017 Jean-Alexandre IBANEZ
** Last update Mon Apr 24 20:41:07 2017 Jean-Alexandre IBANEZ
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "list.h"
#include "get_next_line.h"
#include "my.h"

int	g_exit_value = 0;

void	free_func(char *s, char *path, char **newarg, char **newenv)
{
  if (newenv[1] != NULL)
    free_env(newenv);
  if (newarg[1])
    g_exit_value = my_getnbr(newarg[1]);
  free_tab(newarg);
  free(s);
  if (my_strcmp(path, "NULL") != 0)
    free(path);
  exit(g_exit_value);
}

char	**command_point(char *s, char signe)
{
  int	i;
  char	**new_command;

  i = 0;
  s = remove_point(s, signe);
  new_command = put_in_tab(s, signe);
  while (new_command[i] != NULL)
    {
      new_command[i] = transfo(new_command[i]);
      i++;
    }
  free(s);
  return (new_command);
}

void	sig_hdl(int signum)
{
  if (signum == SIGINT)
    my_printf("\n$>");
}

int		main(int ac, char **av, char **envp)
{
  char		**newenv;
  char		*s;
  char		*path;
  char		**new_command;

  if (ac != 1 || av[1])
    return (84);
  if (!(envp[0]))
    newenv = no_env();
  else
    newenv = my_env(envp);
  path = find_path(newenv, "PATH=");
  if ((isatty(0)))
    my_putstr("$>");
  while ((s = get_next_line(0)) != NULL)
    {
      if (s[0] != '\0')
	{
	  new_command = command_point(s, ';');
	  exec_all(new_command, &newenv, path);
	}
      if ((isatty(0)))
	my_putstr("$>");
    }
  return (g_exit_value);
}
