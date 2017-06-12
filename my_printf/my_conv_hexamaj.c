/*
** my_conv_hexa.c for my_conv_hexa.c in /home/ibanez_j/PSU_2016_my_printf
** 
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
** 
** Started on  Mon Nov 14 12:33:02 2016 Jean-Alexandre IBANEZ
** Last update Mon Nov 14 13:44:02 2016 Jean-Alexandre IBANEZ
*/

#include <stdlib.h>
#include "my.h"

int	hexlen2(unsigned int nb)
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

void	conv_HEXA(unsigned int nb)
{
  int	temp;
  int	i;
  char *arr;

  arr = malloc(sizeof(char) * hexlen2(nb) + 1);
  i = 0;
  temp = nb;
  while (nb != 0)
    {
      nb = nb / 16;
      temp = temp % 16;
      if (temp >= 10)
	temp = temp + 7;
      arr[i] = temp + 48;
      temp = nb;
      i = i + 1;
    }
  arr[i] = '\0';
  arr = my_evil_str(arr);
  my_putstr(arr);
  free(arr);
}
