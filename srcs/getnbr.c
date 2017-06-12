/*
** getnbr.c for PSU_2016_navy in /home/brihoum_b/tek1/PSU_2016_navy/src
**
** Made by Benjamin BRIHOUM
** Login   <brihoum_b@epitech.net>
**
** Started on  Tue Jan 31 18:01:12 2017 Benjamin BRIHOUM
** Last update Fri Apr  7 16:47:21 2017 Jean-Alexandre IBANEZ
*/

int	my_getnbr(char *str)
{
  int	a;
  int	b;

  a = 0;
  b = 0;
  while (str[a] != '\0')
    b = (str[a++] - 48) + (10 * b);
  return (b);
}
