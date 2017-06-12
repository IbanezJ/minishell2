/*
** my_evil_str.c for my_evil_str.c in /home/ibanez_j/PSU_2016_my_printf
** 
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
** 
** Started on  Fri Nov 11 20:17:16 2016 Jean-Alexandre IBANEZ
** Last update Mon Nov 28 15:47:16 2016 Jean-Alexandre IBANEZ
*/

#include <stdlib.h>
#include "my.h"

char	*my_evil_str(char *str)
{
  int	i;
  char	*result;
  int	y;

  y = 0;
  i = my_strlen(str);
  result = malloc(sizeof(str));
  i = i - 1;
  while (i >= 0)
    {
      result[y] = str[i];
      i = i - 1;
      y = y + 1;
    }
  return (result);
}
