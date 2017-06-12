/*
** cd_back.c for minishell2 in /home/ibanez_j/PSU_2016_minishell2/srcs
** 
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
** 
** Started on  Sat Apr  8 14:08:23 2017 Jean-Alexandre IBANEZ
** Last update Sat Apr  8 14:24:51 2017 Jean-Alexandre IBANEZ
*/

#include <unistd.h>
#include "my.h"

void	my_cd_back(char ***envp)
{
  char	buffer[50];
  char	*oldpwd;

  oldpwd = find_path((*envp), "OLDPWD=");
  if (my_strcmp(oldpwd, "NULL") != 0)
    {
      (*envp) = my_setenv((*envp), "OLDPWD", find_path(*envp, "PWD="));
      my_printf("Directory: %s\n", oldpwd);
      chdir(oldpwd);
      (*envp) = my_setenv((*envp), "PWD", getcwd(buffer, 50));
    }
}
