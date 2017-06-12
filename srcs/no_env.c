/*
** no_env.c for minishell in /home/ibanez_j/PSU_2016_minishell1
** 
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
** 
** Started on  Fri Jan 20 15:56:52 2017 Jean-Alexandre IBANEZ
** Last update Sun Jan 22 12:08:34 2017 Jean-Alexandre IBANEZ
*/

#include "my.h"
#include <stdlib.h>

char	**no_env()
{
  char	**env;

  if ((env = malloc(sizeof(char*) * 2)) == NULL)
    return (NULL);
  env[0] = "PATH=/bin:/sbin:/usr/bin:/usr/sbin";
  env[1] = NULL;
  return (env);
}
