/*
** quicksort.c for quicksort.c in /home/ibanez_j/CPE_2016_Pushswap
** 
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
** 
** Started on  Thu Nov 17 13:25:34 2016 Jean-Alexandre IBANEZ
** Last update Tue Apr  4 21:12:33 2017 Jean-Alexandre IBANEZ
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "list.h"

t_list		*my_put_in_start(t_list *list, char *d_name)
{
  t_list	*temp;
  t_list	*element;

  if ((element = malloc(sizeof(*element))) == NULL)
    return (NULL);
  element->d_name = d_name;
  element->next = NULL;
  if (list == NULL)
    {
      return (element);
    }
  else
    {
      temp = list;
      while (temp->next != NULL)
	{
	  temp = temp->next;
	}
      temp->next = element;
      return (list);
    }
}

void		my_show_list(t_list *list)
{
  t_list	*tmp;

  tmp = list;
  while (tmp != NULL)
    {
      my_printf("%s\n", tmp->d_name);
      tmp = tmp->next;
    }
}

t_list	*free_list(t_list *list)
{
  t_list	*temp;
  t_list	*suivant;

  temp = list;
  while (temp != NULL)
    {
      suivant = temp->next;
      free(temp);
      temp = suivant;
    }
  return (NULL);
}
