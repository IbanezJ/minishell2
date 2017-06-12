/*
** get_next_line.c for get_next_line.c in /home/ibanez_j/CPE_2016_getnextline
** 
** Made by Jean-Alexandre IBANEZ
** Login   <ibanez_j@epitech.net>
** 
** Started on  Fri Jan  6 15:36:54 2017 Jean-Alexandre IBANEZ
** Last update Sat Jan 14 10:51:10 2017 Jean-Alexandre IBANEZ
*/

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

char	*my_realloc(char *str, int nb)
{
  char	*new_str;
  int	i;

  i = 0;
  if ((new_str = malloc(sizeof(char) * nb + 1)) == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      new_str[i] = str[i];
      i++;
    }
  free(str);
  return (new_str);
}

static int	treat_result(char **result, int i)
{
  (*result)[i] = '\0';
  (*result) = my_realloc((*result), i + READ_SIZE);
  if ((*result) == NULL)
    return (84);
  return (0);
}

int	free_result(char *buffer)
{
  free(buffer);
  return (84);
}

char		*get_next_line(const int fd)
{
  static int	parseur = 0;
  static char	buffer[READ_SIZE];
  static int	bytes_read = 0;
  char		*result;
  int		i;

  i = 0;
  if ((result = malloc(sizeof(char) * READ_SIZE + 1)) == NULL)
    return (NULL);
  if (bytes_read == 0 && (bytes_read = read(fd, buffer, READ_SIZE)))
    parseur = 0;
  if (bytes_read == -1 || bytes_read == 0)
    if (free_result(result) == 84)
      return (NULL);
  while (buffer[parseur] != '\n' && buffer[parseur] != '\0')
    {
      result[i++] = buffer[parseur++];
      if (--bytes_read == 0 && (bytes_read = read(fd, buffer, READ_SIZE)))
	if ((parseur = treat_result(&result, i)) == 84)
	  return (NULL);
    }
  result[i] = '\0';
  parseur++;
  bytes_read--;
  return (result);
}
