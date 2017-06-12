##
## Makefile for Makefile in /home/ibanez_j/PSU_2016_my_printf
##
## Made by Jean-Alexandre IBANEZ
## Login   <ibanez_j@epitech.net>
##
## Started on  Mon Nov 14 10:30:30 2016 Jean-Alexandre IBANEZ
## Last update Mon Apr  3 21:38:26 2017 Jean-Alexandre IBANEZ
##

SRC	=	my_conv_binary.c	\
		my_conv_otcal.c		\
		my_disp_perc.c		\
		my_evil_str.c		\
		my_printf.c		\
		my_putchar.c		\
		my_put_nbr.c		\
		my_putstr.c		\
		my_strlen.c		\
		my_conv_hexa.c		\
		my_conv_hexamaj.c		\
		my_other_putstr.c	\
		my_disp_ptr.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
