/*
** my_putstr.c for my_putstr.c in /home/ibanez_j/PSU_2016_my_printf_bootstrap
** 
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
** 
** Started on  Tue Nov  8 17:06:11 2016 Jean-Alexandre IBANEZ
** Last update Mon Nov 21 11:29:37 2016 Jean-Alexandre IBANEZ
*/

#include "my.h"

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
}
