/*
** my_strcat.c for my_strdup.c in /home/besnai_m/rendu/Dossier
** 
** Made by michael besnainou
** Login   <besnai_m@epitech.net>
** 
** Started on  Wed Oct 22 17:29:46 2014 michael besnainou
** Last update Fri Apr 10 14:20:33 2015 michael besnainou
*/

#include "my.h"

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (dest[i] != '\0')
    i = i + 1;
  while (src[j] != '\0')
    {
      dest[i] = src[j];
      i = i + 1;
      j = j + 1;
    }
  return (dest);
}
