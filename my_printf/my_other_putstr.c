/*
** my_other_putstr.c for my_other.C in /home/ibanez_j/PSU_2016_my_printf
** 
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
** 
** Started on  Mon Nov 14 11:05:43 2016 Jean-Alexandre IBANEZ
** Last update Mon Nov 14 14:34:23 2016 Jean-Alexandre IBANEZ
*/

#include <stdlib.h>
#include "my.h"

int	octlen2(unsigned int nb)
{
  int	i;

  i = 0;
  while (nb != 0)
    {
      nb = nb / 8;
      i = i + 1;
    }
  return (i);
}

char	*octal(unsigned int nb)
{
  int	temp;
  int	i;
  char	*arr;

  i = 0;
  temp = nb;
  arr = malloc(sizeof(char) * octlen2(nb) + 1);
  while (nb != 0)
    {
      nb = nb / 8;
      temp = temp % 8;
      arr[i] = temp + 48;
      temp = nb;
      i = i + 1;
    }
  arr[i] = '\0';
  arr = my_evil_str(arr);
  return (arr);
  free(arr);
}

void	add_zeros(char *str)
{
  if (str[1] == '\0')
    {
      str[2] = str[0];
      str[1] = '0';
      str[0] = '0';
      str[3] = '\0';
    }
  else if (str[2] == '\0')
    {
      str[2] = str[1];
      str[1] = str[0];
      str[0] = '0';
      str[3] = '\0';
    }
  my_putstr(str);
}

void	other_putstr(char *str)
{
  int	i;
  char *arr;

  arr = malloc(sizeof(char) * 3 + 1);
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] < 32 || str[i] >= 127)
	{
	  my_putchar('\\');
	  arr = octal(str[i]);
	  add_zeros(arr);
	}
      else
	my_putchar(str[i]);
      i = i + 1;
    }
}
