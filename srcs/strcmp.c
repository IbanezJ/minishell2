/*
** strcmp.c for minishell in /home/ibanez_j/PSU_2016_minishell1
** 
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
** 
** Started on  Thu Jan 12 19:24:52 2017 Jean-Alexandre IBANEZ
** Last update Fri Jan 13 20:00:31 2017 Jean-Alexandre IBANEZ
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] == s2[i])
    {
      if (s1[i] == '\0')
	return (0);
      i++;
    }
  return (1);
}
