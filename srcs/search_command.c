/*
** search_command.c for minishell in /home/ibanez_j/PSU_2016_minishell1
** 
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
** 
** Started on  Sat Jan 14 11:12:29 2017 Jean-Alexandre IBANEZ
** Last update Tue Jan 17 20:47:03 2017 Jean-Alexandre IBANEZ
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include "my.h"

char	*add_full_command(char *name, char *command)
{
  int	size_command;
  int	size_name;
  int	j;
  int	i;
  char	*full;

  size_name = my_strlen(name);
  size_command = my_strlen(command);
  j = 0;
  if ((full = malloc(sizeof(char) * (size_name + size_command) + 2)) == NULL)
    return (NULL);
  full[size_name + size_command + 1] = '\0';
  i = 0;
  while (i < size_name)
    {
      full[i] = name[i];
      i++;
    }
  full[i] = '/';
  i++;
  while (i < size_name + size_command + 1)
    {
      full[i++] = command[j++];
    }
  return (full);
}

int	command_ok(char *str, char *command)
{
  int	i;

  i = 0;
  while (str[i] == command[i] && i < my_strlen(command))
    i++;
  if (i == my_strlen(command))
    return (1);
  else
    return (0);
}

char		*find_command(char **path, char *command)
{
  char		*full_command;
  DIR		*dirp;
  int		i;

  i = 0;
  while (path[i] != NULL)
    {
      dirp = opendir(path[i]);
      if (dirp == NULL)
	return (NULL);
      full_command = add_full_command(path[i], command);
      if (access(full_command, X_OK) == 0)
	{
	  free(dirp);
	  free(command);
	  return (full_command);
	}
      i++;
    }
  return (NULL);
}
