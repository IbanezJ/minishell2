/*
** my_conv_binary.c for binary.c in /home/ibanez_j/PSU_2016_my_printf
** 
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
** 
** Started on  Fri Nov 11 13:41:38 2016 Jean-Alexandre IBANEZ
** Last update Mon Nov 14 13:44:28 2016 Jean-Alexandre IBANEZ
*/

#include <stdlib.h>
#include "my.h"

int	binlen(unsigned int nb)
{
  int	i;

  i = 0;
  while (nb != 0)
    {
      nb = nb / 2;
      i = i + 1;
    }
  return (i);
}

void	conv_bin(unsigned int nb)
{
  int	size;
  int	temp;
  int	i;
  char	*arr;

  size = binlen(nb);
  i = 0;
  temp = nb;
  arr = malloc(sizeof(char) * size + 1);
  while (nb != 0)
    {
      nb = nb / 2;
      temp = temp % 2;
      if (temp == 0)
	arr[i] = '0';
      else if (temp == 1)
	arr[i] = '1';
      temp = nb;
      i = i + 1;
    }
  arr[i] = '\0';
  arr = my_evil_str(arr);
  my_putstr(arr);
  free(arr);
}
