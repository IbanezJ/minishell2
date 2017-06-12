/*
** my.h for my.h in /home/ibanez_j/PSU_2016_my_printf_bootstrap
** 
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
** 
** Started on  Tue Nov  8 16:49:22 2016 Jean-Alexandre IBANEZ
** Last update Thu Nov 24 19:51:49 2016 Jean-Alexandre IBANEZ
*/

void	my_put_nbr(int nb);
void	my_putchar(int c);
void	my_putstr(char *str);
int	my_strlen(char *str);
void	conv_bin(unsigned int nb);
char	*my_evil_str(char *str);
void	conv_oct(unsigned int nb);
void	disp_perc();
void	other_putstr(char *str);
void	conv_hexa(unsigned int nb);
void	conv_HEXA(unsigned int nb);
void	disp_ptr(unsigned long nb);
void	my_printf(char *str, ...);
