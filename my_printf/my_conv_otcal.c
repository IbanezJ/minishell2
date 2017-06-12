/*
** my_conv_binary.c for binary.c in /home/ibanez_j/PSU_2016_my_printf
** 
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
** 
** Started on  Fri Nov 11 13:41:38 2016 Jean-Alexandre IBANEZ
** Last update Mon Nov 14 20:30:58 2016 Jean-Alexandre IBANEZ
*/

#include <stdlib.h>
#include "my.h"

char	conv_int_char(int nb)
{
  char	c;

  if (nb == 0)
    c = '0';
  if (nb == 1)
    c = '1';
  if (nb == 2)
    c = '2';
  if (nb == 3)
    c = '3';
  if (nb == 4)
    c = '4';
  if (nb == 5)
    c = '5';
  if (nb == 6)
    c = '6';
  if (nb == 7)
    c = '7';
  return (c);
}

int	octlen(unsigned int nb)
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

void	conv_oct(unsigned int nb)
{
  int	size;
  int	temp;
  int	i;
  char	*arr;

  size = octlen(nb);
  i = 0;
  temp = nb;
  arr = malloc(sizeof(char) * size + 1);
  while (nb != 0)
    {
      nb = nb / 8;
      temp = temp % 8;
      arr[i] = conv_int_char(temp);
      temp = nb;
      i = i + 1;
    }
  arr[i] = '\0';
  arr = my_evil_str(arr);
  my_putstr(arr);
  free(arr);
}
