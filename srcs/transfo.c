/*
** transfo.c for minishell in /home/ibanez_j/PSU_2016_minishell1
** 
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
** 
** Started on  Sun Jan 22 15:05:08 2017 Jean-Alexandre IBANEZ
** Last update Fri Apr  7 13:33:35 2017 Jean-Alexandre IBANEZ
*/

#include <stdlib.h>
#include "my.h"

int	count_char(char *str)
{
  int	i;
  int	compt;

  i = 0;
  compt = 0;
  while (str[i] != '\0')
    {
      if (str[i] != ' ' && str[i] != '\t')
	compt++;
      i++;
    }
  return (compt);
}

char	*transfo(char *str)
{
  int	j;
  int	i;
  char	*new;

  j = 0;
  i = 0;
  if ((new = malloc(sizeof(char) * (count_char(str) + 2) + 1)) == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      if (j != 0)
	{
	  new[j] = ' ';
	  j++;
	}
      while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
	new[j++] = str[i++];
      while ((str[i] == ' ' || str[i] == '\t') && str[i] != '\0')
	i++;
    }
  if (new[j - 1] == ' ')
    new[j - 1] = '\0';
  new[j] = '\0';
  free(str);
  return (new);
}

int	count_goodchar(char *str, char point)
{
  int	i;
  int	compt;

  i = 0;
  compt = 0;
  while (str[i] != '\0')
    {
      if (str[i] != point)
	compt++;
      i++;
    }
  return (compt);
}

int	count_badchar(char *str, char point)
{
  int	i;
  int	count;

  count = 0;
  i = 0;
  while (str[i] == point)
    i++;
  while (str[i] != '\0')
    {
      if (str[i] == point)
	{
	  count++;
	  while (str[i] == point)
	    i++;
	}
      if (str[i] != '\0')
	i++;
    }
  return (count);
}

char	*remove_point(char *str, char point)
{
  int	i;
  int	j;
  char	*new;

  i = 0;
  j = 0;
  if ((new = malloc(sizeof(char) * (count_goodchar(str, point) +
				    count_badchar(str, point)) + 1)) == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      if (j != 0)
	new[j++] = point;
      while (str[i] != point && str[i] != '\0')
	new[j++] = str[i++];
      while ((str[i] == point) && str[i] != '\0')
	i++;
    }
  if (new[j - 1] == point)
    new[j - 1] = '\0';
  new[j] = '\0';
  free(str);
  return (new);
}
