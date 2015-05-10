/*
** parserchamp.c for parserchamp in /home/chouqu_d/rendu/Projet/CPE_2014_corewar
**
** Made by Gregory Chouquet
** Login   <chouqu_d@epitech.net>
**
** Started on  Mon Mar 30 12:18:27 2015 Gregory Chouquet
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "op.h"

void		init_var(t_vm *vm)
{
  vm->a = 0;
  vm->j = 1;
  vm->i = 4;
}

void		call_functions(t_vm *vm, int argc)
{
  get_header(vm);
  fill_tab(vm, argc);
  cycle();
}

int		read_champ(t_vm *vm, int argc, char **argv)
{
  init_var(vm);
  if ((alloc_mem(vm)) != 0)
    return (2);
  while (vm->j <= argc)
    {
      vm->a = 0;
      vm->i = 3;
      if ((vm->fd = open(argv[vm->j], O_RDONLY)) < 0)
	return (2);
      while ((vm->ret = read(vm->fd, &vm->buffer, 1)) > 0)
	vm->champ[vm->a++] = vm->buffer;
      if ((vm->a - 2176) >= MEM_SIZE / argc)
	{
	  my_putstr("Not enough memory space\n");
	  return (2);
	}
      my_putstr("Champion n°");
      my_put_nbr(vm->j);
      vm->champ[vm->a] = 0;
      call_functions(vm, argc);
      vm->j++;
      my_putchar('\n');
    }
  return (0);
}

int		check_files(char **tab)
{
  int		i;
  int		b;
  int		fd;

  i = 1;
  while (tab[i] != '\0')
    {
      b = my_strlen(tab[i]);
      if ((fd = open(tab[i], O_RDONLY)) < 0)
	{
	  my_putstr("File ");
	  my_putstr(tab[i]);
	  my_putstr(" not accessible\n");
	  return (2);
	}
      if (b < 5 || tab[i][b - 1] != 'r' || tab[i][b - 2] != 'o' ||
	  tab[i][b - 3] != 'c' || tab[i][b - 4] != '.')
	{
	  my_putstr("Error: wrong type of file, only \".cor\" are accepted.\n");
	  return (2);
	}
      i++;
    }
  return (0);
}

int		detec_dump()
{
  my_putstr("dumping...\n");
  return (0);
}

int		main(int argc, char **argv)
{
  t_vm		*vm;
  int	a;

  a = 0;
  if (my_strncmp(argv[1], "-dump\0", 6) == 0)
    argc= argc - 2;
  if (argc > 5 || argc == 1 || argc <= 0)
    {
      my_putstr("We need at least one champion, and maximum of 4 to play\n");
      return (2);
    }
  if (my_strncmp(argv[1], "-dump\0", 6) == 0)
    {
      my_putstr(argv[2]);
      my_putchar('\n');
      a = my_getnbr(argv[2]);
      detec_dump();
      argv[1] = argv[3];
      argv[2] = argv[4];
      argv[3] = argv[5];
      argv[4] = argv[6];
      argv[5] = argv[7];
    }
  if (check_files(argv) != 0)
    return (2);
  if ((vm = malloc(sizeof(t_vm) + 5)) == NULL)
    return (my_putstr_error("Can't perform malloc\n"));
  if ((vm->champ = malloc(sizeof(vm->champ) * 10000)) == NULL)
    return (my_putstr_error("Can't perform malloc\n"));
  argc = argc - 1;
  read_champ(vm, argc, argv);
  free(vm);
  return (0);
}
