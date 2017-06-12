/*
** my_cd.c for minishell in /home/ibanez_j/PSU_2016_minishell1
** 
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
** 
** Started on  Tue Jan 17 11:41:04 2017 Jean-Alexandre IBANEZ
** Last update Sat Apr  8 14:32:02 2017 Jean-Alexandre IBANEZ
*/

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

void	initialize_var(int *i, int *j, int *size_path, char *path)
{
  *i = 0;
  *j = 0;
  *size_path = my_strlen(path);
}

char	*replace_tild(char *str, int rank, char *path)
{
  int	x;
  int	j;
  int	i;
  char	*result;
  int	size_path;

  initialize_var(&i, &j, &size_path, path);
  if ((result = malloc(sizeof(char) * ((size_path +
					my_strlen(str)) + 1))) == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      if (i == rank)
	{
	  x = i;
	  while (x < size_path)
	    result[x++] = path[j++];
	  i++;
	}
      result[x++] = str[i];
      if (str[i] != '\0')
	i++;
    }
  result[x] = '\0';
  return (result);
}

int	rank_tild(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '~')
	return (i);
      i++;
    }
  return (-1);
}

void	general_case(char *str, char *path, int *result, char ***envp)
{
  char	buffer[50];
  int	first_size;
  int	second_size;

  first_size = my_strlen(str);
  if (rank_tild(str) != -1)
    str = replace_tild(str, rank_tild(str), path);
  second_size = my_strlen(str);
  (*result) = chdir(str);
  if ((*result) != -1)
    {
      (*envp) = my_setenv((*envp), "OLDPWD", find_path(*envp, "PWD="));
      my_printf("Directory: %s\n", getcwd(buffer, 50));
      (*envp) = my_setenv((*envp), "PWD", getcwd(buffer, 50));
    }
  if (second_size != first_size)
    free(str);
}

int		my_cd(char *str, char ***envp)
{
  char		buffer[50];
  char		*path;
  int		result;

  path = find_path((*envp), "HOME=");
  if (my_strcmp(str, "null") == 0 || my_strcmp(str, "--") == 0)
    {
      if (my_strcmp(path, "NULL") == 0)
	{
	  my_printf("cd: No home directory.\n");
	  g_exit_value = 1;
	  return (84);
	}
      if ((result = chdir(path)) != -1)
	{
	  (*envp) = my_setenv((*envp), "OLDPWD", find_path(*envp, "PWD="));
	  my_printf("Directory: %s\n", getcwd(buffer, 50));
	  (*envp) = my_setenv((*envp), "PWD", getcwd(buffer, 50));
	}
    }
   else
     general_case(str, path,  &result, envp);
  if (my_strcmp(path, "NULL") != 0)
    free(path);
  return (result);
}
