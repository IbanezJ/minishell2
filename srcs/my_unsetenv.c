/*
** my_unsetenv.c for minishell in /home/ibanez_j/PSU_2016_minishell1
** 
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
** 
** Started on  Sat Jan 21 12:14:01 2017 Jean-Alexandre IBANEZ
** Last update Sun Jan 22 16:39:28 2017 Jean-Alexandre IBANEZ
*/

#include <stdlib.h>
#include "my.h"

void	initialize(int *i, int *j, int *nb_env, char **envp)
{
  *i = 0;
  *j = 0;
  *nb_env = count_nbenv(envp);
}

char	**remove_element(char *remove, char **envp)
{
  int	j;
  char	**new_envp;
  int	i;
  int	nb_env;

  initialize(&i, &j, &nb_env, envp);
  if ((new_envp = malloc(sizeof(char*) * (nb_env))) == NULL)
    return (NULL);
  while (envp[i] != '\0')
    {
      if (my_strcmp(envp[i], remove) == 0)
	i++;
      else
	{
	  if ((new_envp[j] = malloc(sizeof(char) * my_strlen(envp[i]) + 1))
	      == NULL)
	    return (NULL);
	  new_envp[j] = cpy_env(new_envp[j], envp[i]);
	  i++;
	  j++;
	}
    }
  new_envp[j] = NULL;
  free_env(envp);
  return (new_envp);
}

char	**my_unsetenv(char **envp, char **argv)
{
  int	compt_arg;
  int	i;

  compt_arg = 0;
  i = 0;
  while (envp[i] != NULL)
    {
      while (argv[compt_arg] != NULL)
	{
	  if (check_exist(envp[i], argv[compt_arg]) == 0)
	    {
	      envp = remove_element(envp[i], envp);
	      i--;
	    }
	  compt_arg++;
	}
      compt_arg = 0;
      i++;
    }
  return (envp);
}
