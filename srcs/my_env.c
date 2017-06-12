/*
** my_env.c for minishell1 in /home/ibanez_j/PSU_2016_minishell1
** 
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
** 
** Started on  Tue Jan 17 14:47:53 2017 Jean-Alexandre IBANEZ
** Last update Fri Apr  7 13:57:15 2017 Jean-Alexandre IBANEZ
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

int	count_nbenv(char **envp)
{
  int	i;

  i = 0;
  while (envp[i] != NULL)
    i++;
  return (i);
}

char	*cpy_env(char *newenv, char *env)
{
  int	i;

  i = 0;
  while (env[i] != '\0')
    {
      newenv[i] = env[i];
      i++;
    }
  newenv[i] = '\0';
  return (newenv);
}

char	**my_env(char **envp)
{
  char	**newenv;
  int	nb_env;
  int	i;

  nb_env = count_nbenv(envp);
  if ((newenv = malloc(sizeof(char*) * (nb_env + 2))) == NULL)
    return (NULL);
  i = 0;
  while (envp[i] != '\0')
    {
      if ((newenv[i] = malloc(sizeof(char) * my_strlen(envp[i]) + 1)) == NULL)
	return (NULL);
      newenv[i] = cpy_env(newenv[i], envp[i]);
      i++;
    }
  newenv[i] = '\0';
  return (newenv);
}

void	display_env(char **env)
{
  int	i;

  i = 0;
  while (env[i] != '\0')
    {
      my_printf("%s\n", env[i]);
      i++;
    }
}

void	free_env(char **envp)
{
  int	size_env;
  int	i;

  size_env = count_nbenv(envp);
  i = 0;
  while (i < size_env)
    {
      free(envp[i]);
      i++;
    }
  free(envp);
}
