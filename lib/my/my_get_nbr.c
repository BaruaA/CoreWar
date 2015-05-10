/*
** my_get_nbr.c for GetNbr in /home/barua_a/Rendu/ElemProg/CPE_2014_allum1
** 
** Made by Amlan BARUA
** Login   <barua_a@epitech.net>
** 
** Started on  Fri Feb 20 16:54:44 2015 Amlan BARUA
** Last update Sat Apr 11 16:10:25 2015 Amlan BARUA
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

int	my_getnbr(char *str)
{
  int	i;
  int	n;

  i = 0;
  n = 0;
  if (str[i] == '\0')
    exit(0);
  if (str[0] == '-')
    {
      my_putstr_error("Error: Invalid nbr_cycle\n");
      exit(2);
    }
  while (str[i] != '\0')
    {
      if ((str[i] < '0' || str[i] > '9'))
	{
	  my_putstr("Error: Invalid nbr_cycle\n");
	  exit(2);
	}
      n = n + str[i] - 48;
      n = n * 10;
      i++;
    }
  n = n / 10;
  return (n);
}
