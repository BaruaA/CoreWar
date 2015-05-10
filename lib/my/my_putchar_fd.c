/*
** my_putchar_fd.c for my_putchar_fd in /home/besnai_m/rendu/C_Prog_Elem/CPE_2014_corewar/lib/my
** 
** Made by michael besnainou
** Login   <besnai_m@epitech.net>
** 
** Started on  Thu Apr  9 15:01:44 2015 michael besnainou
** Last update Thu Apr  9 15:25:03 2015 Gregory Chouquet
*/

#include <unistd.h>

void	my_putchar_fd(char c, int fd_create)
{
  write(fd_create, &c, 1);
}
