/*
** my_strlen.c for my_strlen.c in /home/ibanez_j/PSU_2016_my_printf_bootstrap
** 
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
** 
** Started on  Tue Nov  8 17:07:01 2016 Jean-Alexandre IBANEZ
** Last update Tue Nov  8 17:08:16 2016 Jean-Alexandre IBANEZ
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      i = i + 1;
    }
  return (i);
}
