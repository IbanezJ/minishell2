/*
** good_env_name.c for minishell in /home/ibanez_j/PSU_2016_minishell2/srcs
** 
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
** 
** Started on  Fri Apr  7 14:05:30 2017 Jean-Alexandre IBANEZ
** Last update Fri Apr  7 14:06:00 2017 Jean-Alexandre IBANEZ
*/

int	good_env_name(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] < '0' || (str[i] > '9' && str[i] < 'A') ||
	  (str[i] > 'Z' && str[i] < '_') || (str[i] > '_' && str[i] < 'a') ||
	  str[i] > 'z')
	return (1);
      i++;
    }
  return (0);
}
