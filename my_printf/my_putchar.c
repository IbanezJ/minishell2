/*
** fctutiles.c for fctsutiles.c in /home/ibanez_j/PSU_2016_my_printf_bootstrap
** 
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
** 
** Started on  Tue Nov  8 17:02:54 2016 Jean-Alexandre IBANEZ
** Last update Sat Nov 12 18:45:11 2016 Jean-Alexandre IBANEZ
*/

#include <unistd.h>

void	my_putchar(int c)
{
  write(1, &c, 1);
}
