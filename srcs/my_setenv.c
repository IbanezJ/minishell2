/*
** my_setenv.c for minishell1 in /home/ibanez_j
** 
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
** 
** Started on  Thu Jan 19 16:35:44 2017 Jean-Alexandre IBANEZ
** Last update Fri Apr  7 14:06:37 2017 Jean-Alexandre IBANEZ
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int	check_exist(char *envp, char *new)
{
  int	size_new;
  int	i;

  i = 0;
  size_new = my_strlen(new);
  while (envp[i] == new[i])
    {
      i++;
    }
  if (i == size_new)
    return (0);
  return (1);
}

char	*change_envp(char *envp, char *new, char *value)
{
  int	j;
  int	i;
  char	*new_envp;

  j = 0;
  i = 0;
  if ((new_envp = malloc(sizeof(char) * (my_strlen(new) +
					 my_strlen(value) + 1) + 1)) == NULL)
    return (NULL);
  while (i < my_strlen(new))
    {
      new_envp[i] = envp[i];
      i++;
    }
  new_envp[i] = '=';
  i++;
  while (j < my_strlen(value))
    {
      new_envp[i] = value[j];
      i++;
      j++;
    }
  new_envp[i] = '\0';
  free(envp);
  return (new_envp);
}

char	*new_element(char *new, char *value)
{
  char	*element;
  int	j;
  int	i;

  j = 0;
  i = 0;
  if ((element = malloc(sizeof(char) * (my_strlen(new) + my_strlen(value)
					+ 1) + 1)) == NULL)
    return (NULL);
  while (i < my_strlen(new))
    {
      element[i] = new[i];
      i++;
    }
  element[i] = '=';
  i++;
  while (j < my_strlen(value))
    {
      element[i] = value[j];
      i++;
      j++;
    }
  element[i] = '\0';
  return (element);
}

char	**if_new(char **envp, char *new, char *value)
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
  new_envp[i] = new_element(new, value);
  new_envp[i + 1] = NULL;
  free_env(envp);
  return (new_envp);
}

char	**my_setenv(char **envp, char *new, char *value)
{
  int	i;

  i = 0;
  if (good_env_name(new) == 1)
    {
      g_exit_value = 1;
      my_printf("setenv: Variable name must "
		"contain alphanumeric characters.\n");
    }
  if (new && value)
    {
      while (envp[i] != '\0')
	{
	  if (check_exist(envp[i], new) == 0)
	    {
	      envp[i] = change_envp(envp[i], new, value);
	      return (envp);
	    }
	  i++;
	}
      envp = if_new(envp, new, value);
      return (envp);
    }
  return (NULL);
}
