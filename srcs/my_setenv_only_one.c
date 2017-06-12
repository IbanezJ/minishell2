/*
** my_setenv_only_one.c for minishell in /home/ibanez_j/PSU_2016_minishell1
** 
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
** 
** Started on  Sat Jan 21 11:29:56 2017 Jean-Alexandre IBANEZ
** Last update Fri Apr  7 14:15:17 2017 Jean-Alexandre IBANEZ
*/

#include <stdlib.h>
#include "my.h"

char	*change_envp_one(char *envp, char *new)
{
  int	i;
  char	*new_envp;

  i = 0;
  if ((new_envp = malloc(sizeof(char) * (my_strlen(new) + 1) + 1)) == NULL)
    return (NULL);
  while (i < my_strlen(new))
    {
      new_envp[i] = envp[i];
      i++;
    }
  new_envp[i] = '=';
  new_envp[i + 1] = '\0';
  free(envp);
  return (new_envp);
}

char	*new_element_one(char *new)
{
  char	*element;
  int	i;

  i = 0;
  if ((element = malloc(sizeof(char) * (my_strlen(new) + 1) + 1)) == NULL)
    return (NULL);
  while (i < my_strlen(new))
    {
      element[i] = new[i];
      i++;
    }
  element[i] = '=';
  i++;
  element[i] = '\0';
  return (element);
}

char	**if_new_one(char **envp, char *new)
{
  char	**new_envp;
  int	i;
  int	nb_env;

  nb_env = count_nbenv(envp);
  if ((new_envp = malloc(sizeof(char*) * (nb_env + 2))) == NULL)
    return (NULL);
  i = 0;
  while (envp[i] != '\0')
    {
      if ((new_envp[i] = malloc(sizeof(char) * my_strlen(envp[i]) + 1))
	  == NULL)
	return (NULL);
      new_envp[i] = cpy_env(new_envp[i], envp[i]);
      i++;
    }
  new_envp[i] = new_element_one(new);
  new_envp[i + 1] = NULL;
  free_env(envp);
  return (new_envp);
}

char	**my_setenv_only_one(char **envp, char *new)
{
  int	i;

  i = 0;
  if (good_env_name(new) == 1)
    {
      g_exit_value = 1;
      my_printf("setenv: Variable name must "
		"contain alphanumeric characters.\n");
    }
  while (envp[i] != '\0')
    {
      if (check_exist(envp[i], new) == 0)
	{
	  envp[i] = change_envp_one(envp[i], new);
	  return (envp);
	}
      i++;
    }
  envp = if_new_one(envp, new);
  return (envp);
}
