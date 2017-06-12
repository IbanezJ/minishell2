/*
** list.h for minishell in /home/ibanez_j/PSU_2016_minishell1
** 
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
** 
** Started on  Thu Nov 17 13:29:47 2016 Jean-Alexandre IBANEZ
** Last update Tue Jan 17 21:12:39 2017 Jean-Alexandre IBANEZ
*/

#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>

#ifndef LIST_H_
# define LIST_H_

typedef struct	s_list
{
  char		*d_name;
  struct s_list	*next;
}		t_list;

void    aff_env(t_list *new_env);
t_list  *env_in_list(char **envp);
void	my_show_list(t_list *list);
t_list	*my_put_in_start(t_list *list, char *d_name);
t_list  *free_list(t_list *list);

#endif
