/*
** get_next_line.c for get_next in /home/chouqu_d/rendu/CPE_2014_bsq
** 
** Made by Gregory Chouquet
** Login   <chouqu_d@epitech.net>
** 
** Started on  Sun Jan 18 23:48:03 2015 Gregory Chouquet
** Last update Sat Apr 11 14:21:21 2015 Amlan BARUA
*/

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

char		*my_realloc(char *str)
{
  char		*temp;
  int		i;
  int		j;

  j = 0;
  while (str[j] != '\0')
    j++;
  i = 0;
  temp = malloc(j + BUFFER_SIZE + 3);
  if (temp == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      temp[i] = str[i];
      i++;
    }
  temp[i] = '\0';
  return (temp);
}

char            *my_strcpy(char *dest, char *src, int n, int end)
{
  int           i;

  i = 0;
  if (end != 9876543)
    {
      while (i != end)
        {
          dest[n] = src[i];
          src[i] = 0;
          i++;
          n++;
        }
      dest[n] = 0;
    }
  else
    {
      while (src[i] != '\0')
        {
          dest[n] = src[i];
          src[i] = 0;
          n++;
          i++;
        }
    }
  return (dest);
}

int		complete(char *tab, char *line, int *n, int *i)
{
  int		j;

  j = 0;
  while (tab[*i] != '\0')
    {
      if (tab[*i] == '\n')
	{
	  line[j] = 0;
	  *i = *i + 1;
	  return (1);
	}
      line[j] = tab[*i];
      *i = *i + 1;
      j++;
    }
  line[j] = 0;
  *n = j;
  return (0);
}

int		fill(int fd, char *tab, int *i, t_struct *init)
{
  int		error;

  error = 1;
  while (error > 0)
    {
      error = read(fd, tab,  BUFFER_SIZE);
      tab[BUFFER_SIZE] = 0;
      while (tab[*i] != '\0')
	{
          if (tab[*i] == '\n')
            {
              init->line = my_strcpy(init->line, tab, init->n, *i);
              *i = *i + 1;
              return (1);
            }
          *i = *i + 1;
	}
      init->line = my_realloc(init->line);
      init->line = my_strcpy(init->line, tab, init->n, 9876543);
      init->n = init->n + *i;
      *i = 0;
    }
  return (0);
}

char		*get_next_line(const int fd)
{
  static char  	tab[BUFFER_SIZE];
  static int	i;
  static int	final;
  t_struct	init;

  init.f = 0;
  init.n = 0;
  if (final == 1)
    return (NULL);
  init.line = malloc(BUFFER_SIZE + 1);
  if (init.line == NULL)
    return (NULL);
  if (complete(tab, init.line, &init.n, &i) == 1)
    return (init.line);
  while (init.f != BUFFER_SIZE)
    {
      tab[init.f] = 0;
      init.f++;
    }
  if (fill(fd, tab, &i, &init) == 1)
    return (init.line);
  final = 1;
  init.line[init.n] = 0;
  return (init.line);
}
