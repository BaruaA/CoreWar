/*
** get_header.c for get_header in /home/besnai_m/rendu/C_Prog_Elem/CPE_2014_corewar/corewar/src
**
** Made by michael besnainou
** Login   <besnai_m@epitech.net>
**
** Started on  Sat Apr 11 12:57:13 2015 michael besnainou
** Last update Sat Apr 11 13:08:59 2015 michael besnainou
*/

#include "my.h"
#include "op.h"

void		get_name(t_vm *vm)
{
  my_putstr(NAME);
  while (vm->i != PROG_NAME_LENGTH - 1)
    {
      if (vm->champ[vm->i] >= 32 && vm->champ[vm->i] <= 126)
	{
	  my_putchar(vm->champ[vm->i]);
	  vm->champ[vm->i] = '\0';
	}
      vm->i++;
    }
  my_putchar('|');
}

void		get_comment(t_vm *vm)
{
  my_putstr(COMMENT);
  vm->i = 129;
  while (vm->i != COMMENT_LENGTH - 1)
    {
      if (vm->champ[vm->i] >= 32 && vm->champ[vm->i] <= 126)
	{
	  my_putchar(vm->champ[vm->i]);
	  vm->champ[vm->i] = '\0';
	}
      vm->i++;
    }
}

void		get_header(t_vm *vm)
{
  get_name(vm);
  get_comment(vm);
}
