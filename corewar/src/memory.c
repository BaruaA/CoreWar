/*
** memory.c for memory.c in /home/besnai_m/rendu/C_Prog_Elem/CPE_2014_corewar/corewar/src
**
** Made by michael besnainou
** Login   <besnai_m@epitech.net>
**
** Started on  Sat Apr 11 12:52:26 2015 michael besnainou
** Last update Sat Apr 11 14:49:32 2015 michael besnainou
*/

#include <stdlib.h>
#include "my.h"
#include "op.h"

void		cycle()
{
  int		cycle;
  int		cycle_die;

  cycle = 0;
  cycle_die = CYCLE_TO_DIE;
  while (cycle_die >= 5)
    {
      while (cycle <= CYCLE_TO_DIE)
	{
	  cycle++;
	}
      cycle = 0;
      cycle_die = cycle_die - CYCLE_DELTA;
    }
}

void		empty_tab(t_vm *vm)
{
  int		i;

  i = 0;
  while (i != MEM_SIZE + 5)
    {
      vm->memory[i] = '\0';
      i++;
    }
}

int		alloc_mem(t_vm *vm)
{
  if ((vm->memory = malloc(MEM_SIZE)) == NULL)
    return (my_putstr_error("Can't perform malloc\n"));
  empty_tab(vm);
  return (0);
}

void		fill_tab(t_vm *vm, int argc)
{
  int		size;
  static int	j;
  int		index;

  index = (MEM_SIZE / argc) * j;
  size = sizeof(header_t);
  while (vm->champ[size] != '\0')
    {
      vm->memory[index] = vm->champ[size];
      index++;
      size++;
    }
  j++;
}
