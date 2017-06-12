/*
** printf.c for printf.c in /home/ibanez_j/PSU_2016_my_printf
** 
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
** 
** Started on  Fri Nov 18 14:32:18 2016 Jean-Alexandre IBANEZ
** Last update Fri Nov 18 17:30:44 2016 Jean-Alexandre IBANEZ
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

unsigned long	hexlonglen(unsigned long nb)
{
  unsigned long	i;

  i = 0;
  while (nb != 0)
    {
      nb = nb / 2;
      i = i + 1;
    }
  return (i);
}

void		conv_long_hexa(unsigned long nb)
{
  unsigned long	temp;
  unsigned long	i;
  char		*arr;

  arr = malloc(sizeof(char) * hexlonglen(nb) + 1);
  i = 0;
  temp = nb;
  while (nb != 0)
    {
      nb = nb / 16;
      temp = temp % 16;
      if (temp >= 10)
	temp = temp + 39;
      arr[i] = temp + 48;
      temp = nb;
      i = i + 1;
    }
  arr[i] = '\0';
  arr = my_evil_str(arr);
  my_putstr(arr);
  free(arr);
}

void		disp_ptr(unsigned long nb)
{
  my_putstr("0x");
  conv_long_hexa(nb);
}
