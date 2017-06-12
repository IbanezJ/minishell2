##
## Makefile for minishell in /home/ibanez_j/PSU_2016_minishell
## 
## Made by Jean-Alexandre IBANEZ
## Login   <ibanez_j@epitech.net>
## 
## Started on  Mon Dec 12 16:39:00 2016 Jean-Alexandre IBANEZ
## Last update Sat Apr  8 14:15:18 2017 Jean-Alexandre IBANEZ
##

CC	= gcc

RM	= rm -f

CFLAGS	+= -Wextra -Wall -g
CLFAGS	+= -ansi -pedantic
CFLAGS	+= -I./include/

NAME	= mysh

SRCS	=	main.c	\
		find_path.c	\
		forking.c	\
		get_next_line.c	\
		search_command.c	\
		strcmp.c	\
		word_tab.c	\
		my_cd.c		\
		simple_list.c	\
		my_env.c	\
		basics_disp.c	\
		my_setenv.c	\
		no_env.c	\
		my_setenv_only_one.c	\
		my_unsetenv.c	\
		transfo.c	\
		execution.c	\
		pipe.c		\
		good_env_name.c	\
		getnbr.c	\
		cd_back.c

OBJS	= $(join $(addsuffix ./srcs/, $(dir $(SRCS))), $(notdir $(SRCS:.c=.o)))

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) -L./my_printf/ -lmy

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re
