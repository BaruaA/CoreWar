/*
** my_put_nbr.c for my_put_nbr in 
** 
** Made by michael besnainou
** Login   <besnai_m@epitech.net>
** 
** Started on  Mon Mar 16 12:48:05 2015 michael besnainou
** Last update Mon Mar 16 12:59:30 2015 michael besnainou
*/

#include "my.h"

void	my_put_nbr(int nb)
{
  if (nb > 10)
    my_put_nbr(nb / 10);
  my_putchar(nb % 10 + 48);
}
