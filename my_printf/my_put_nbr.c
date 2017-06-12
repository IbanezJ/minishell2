/*
** my_put_nbr.c for my_put_nbr.c in /home/ibanez_j/CPool_workshoplib/lib/my
** 
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
** 
** Started on  Thu Oct 20 10:36:24 2016 Jean-Alexandre IBANEZ
** Last update Thu Nov 17 11:34:15 2016 Jean-Alexandre IBANEZ
*/

#include "my.h"

void	my_put_nbr(int nb)
{
  int	mod;
  int	tmp;

  mod = 1;
  if (nb < 0)
    {
      nb = nb * -1;
      my_putchar('-');
    }
  tmp = nb;
  while (nb > 9)
    {
      nb = nb / 10;
      mod = mod * 10;
    }
  while (mod >= 1)
    {
      my_putchar(tmp / mod + 48);
      tmp = tmp % mod;
      mod = mod / 10;
    }
}
