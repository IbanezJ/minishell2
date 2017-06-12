/*
** my_printf.c for my_printf.c in /home/ibanez_j/PSU_2016_my_printf
** 
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
** 
** Started on  Thu Nov 10 11:41:56 2016 Jean-Alexandre IBANEZ
** Last update Mon Apr  3 21:34:49 2017 Jean-Alexandre IBANEZ
*/

#include <stdarg.h>
#include <unistd.h>
#include "my.h"
#include "test.h"

t_struct	g_arr_struct[13] = {{&my_putstr, 's'},
				    {&my_putchar, 'c'},
				    {&conv_bin, 'b'},
				    {&conv_oct, 'o'},
				    {&my_put_nbr, 'i'},
				    {&my_put_nbr, 'd'},
				    {&my_put_nbr, 'u'},
				    {&disp_perc, '%'},
				    {&other_putstr, 'S'},
				    {&conv_hexa, 'x'},
				    {&conv_HEXA, 'X'},
				    {&disp_ptr, 'p'},
				    {NULL, -1}};

void	disp_flag(int rank_arr, va_list list, char *str, int i)
{
  while (g_arr_struct[rank_arr].letter != -1)
    {
      if (str[i + 1] == '%')
	{
	  my_putchar('%');
	  rank_arr = 11;
	}
      else if (str[i + 1] == g_arr_struct[rank_arr].letter)
	g_arr_struct[rank_arr].fptr(va_arg(list, void *));
      rank_arr = rank_arr + 1;
    }
}

void		my_printf(char *str, ...)
{
  va_list	list;
  int		i;
  int		rank_arr;

  rank_arr = 0;
  i = 0;
  va_start(list, str);
  while (str[i] != '\0')
    {
      if (str[i] == '%')
	{
	  disp_flag(rank_arr, list, str, i);
	  i = i + 1;
	}
      else
	my_putchar(str[i]);
      i = i + 1;
      rank_arr = 0;
    }
  va_end(list);
}
