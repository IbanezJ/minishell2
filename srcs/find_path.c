/*
** find_path.c for minishell in /home/ibanez_j/PSU_2016_minishell1
** 
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
** 
** Started on  Thu Jan 12 18:19:46 2017 Jean-Alexandre IBANEZ
** Last update Tue Apr  4 21:01:37 2017 Jean-Alexandre IBANEZ
*/

#include <stdlib.h>
#include "my.h"

char	*realloc_to_path(char *str, char *path)
{
  int	compt;
  char	*new_str;
  int	i;

  compt = 0;
  i = my_strlen(path);
  if ((new_str = malloc(sizeof(char) * (my_strlen(str) - i + 1))) == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      new_str[compt] = str[i];
      i++;
      compt++;
    }
  new_str[compt] = '\0';
  return (new_str);
}

int	check_ok(char *str, char *path)
{
  int	i;

  i = 0;
  while (str[i] == path[i] && i < my_strlen(path))
    i++;
  if (i == my_strlen(path))
    return (1);
  else
    return (0);
}

char	*find_path(char **envp, char *path)
{
  int	j;
  char	*result;
  int	temp;
  int	i;

  temp = -1;
  j = 0;
  i = 0;
  while (envp[i] != '\0')
    {
      if (check_ok(envp[i], path) == 1)
	temp = i;
      i++;
    }
  if (temp == -1)
    return ("NULL");
  i = my_strlen(path);
  if ((result = malloc(sizeof(char) * (my_strlen(envp[temp]) -
				       my_strlen(path)) + 1)) == NULL)
    return (NULL);
  while (envp[temp][i] != '\0')
    result[j++] = envp[temp][i++];
  result[j] = '\0';
  return (result);
}
