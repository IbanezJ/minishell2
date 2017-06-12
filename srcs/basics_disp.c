/*
** basics_disp.c for minishell1 in /home/ibanez_j/PSU_2016_minishell1
** 
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
** 
** Started on  Tue Jan 17 21:17:51 2017 Jean-Alexandre IBANEZ
** Last update Sat Apr  8 15:51:53 2017 Jean-Alexandre IBANEZ
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
}

void	printf_before_space(char *str)
{
  int	i;

  i = 0;
  while (str[i] != ' ' && str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
  my_putstr(": Command not found.\n");
}
