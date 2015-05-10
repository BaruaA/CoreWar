/*
** my_putstr_error.c for my_put_str_error in /home/besnai_m/rendu/C_Prog_Elem/CPE_2014_corewar/lib/my
** 
** Made by michael besnainou
** Login   <besnai_m@epitech.net>
** 
** Started on  Tue Apr  7 12:32:54 2015 michael besnainou
** Last update Tue Apr  7 12:42:29 2015 michael besnainou
*/

#include <stdlib.h>
#include <unistd.h>

int	my_putstr_error(char *str)
{
  if (str == NULL)
    return (0);
  while (*str)
    write(2, str++, 1);
  return (2);
}
