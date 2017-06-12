/*
** my_getnbr.c for my_getnbr.c in /home/ibanez_j/CPool_workshoplib/lib/my
** 
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
** 
** Started on  Thu Oct 20 11:44:28 2016 Jean-Alexandre IBANEZ
** Last update Fri Nov 18 17:01:51 2016 Jean-Alexandre IBANEZ
*/

#include <unistd.h>
#include "my.h"

char	reduc1(unsigned long i, char *str, char *tab, unsigned long j)
{
   while (str[i] != '\0')
    {
      if ((str[i] >= 48) && (str[i] <= 57))
	{
	  if (str[i - 1] == '-')
	    {
	      tab[0] = '-';
	      j = 1;
	    }
	  while ((str[i] >= 48) && (str[i] <= 57))
	    {
	      tab[j] = str[i];
	      i = i + 1;
	      j = j + 1;
	    }
	  str[i + 1] = '\0';
	  tab[j] = '\0';
	}
      i = i + 1;
    }
}

unsigned long	reducmod(unsigned long i, unsigned long j)
{
  unsigned long	mod;

  mod = 1;
  while (i < j)
    {
      mod = mod * 10;
      i = i + 1;
    }
  return (mod);
}

unsigned long	my_getnbr(char *str)
{
  unsigned long	mod;
  unsigned long	x;
  unsigned long	i;
  unsigned long	j;
  char		tab[255];

  x = 0;
  j = 0;
  i = 0;
  reduc1(i, str, tab, j);
  j = my_strlen(tab);
  i = 1;
  mod = reducmod(i, j);
  i = 0;
  while (j > 0)
    {
      i = i + (tab[x] - 48) * mod;
      mod = mod / 10;
      j = j - 1;
      x = x + 1;
    }
  return (i);
}
