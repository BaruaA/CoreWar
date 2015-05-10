/*
** parserchamp.c for parserchamp in /home/chouqu_d/rendu/Projet/CPE_2014_corewar
**
** Made by Gregory Chouquet
** Login   <chouqu_d@epitech.net>
**
** Started on  Mon Mar 30 12:18:27 2015 Gregory Chouquet
** Last update Sat Apr 11 14:57:37 2015 Amlan BARUA
*/

#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include "my.h"
#include "op.h"

int		name_string(t_core *core, int a, int fd_create)
{
  static int	stop;

  my_putchar_fd(0xea, fd_create);
  my_putchar_fd(0x83, fd_create);
  my_putchar_fd(0xf3, fd_create);
  while (a <= 141)
    {
      while (core->champ[a] == ' ' && stop < 1)
	a++;
      stop = 1;
      if (core->champ[a] == '"' && stop < 2)
	{
	  a++;
	  while (core->champ[a] != '"')
	    {
	      my_putchar_fd(core->champ[a], fd_create);
	      a++;
	    }
	  stop = 2;
	}
      else
	my_putchar_fd(0x00, fd_create);
      a++;
    }
  return (0);
}

int		comment_string(t_core *core, int p, int fd_create)
{
  static int	quit;

  my_putchar_fd(0x00, fd_create);
  my_putchar_fd(0x00, fd_create);
  while (p <= COMMENT_LENGTH)
    {
      while (core->champ[p] == ' ' && quit < 1)
	p++;
      quit = 1;
      if (core->champ[p] == '"' && quit < 2)
	{
	  p++;
	  while (core->champ[p] != '"')
	    {
	      my_putchar_fd(core->champ[p], fd_create);
	      p++;
	    }
	  quit = 2;
	}
      else
	my_putchar_fd(0x00, fd_create);
      p++;
    }
  return (0);
}

int		check_file(char **tab)
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
	  my_putstr("Error: the file: ");
	  my_putstr(tab[i]);
	  my_putstr(" dosen't exist.\n");
	  return (2);
	}
	if (b < 3 || tab[i][b - 1] != 's' || tab[i][b - 2] != '.')
	  {
	    my_putstr("Error: wrong type of file, only \".s\" are accepted.\n");
	    return (2);
	  }
	i++;
    }
  return (0);
}

void		read_file(t_core *core, int fd, int p, int fd_create)
{
  int		a;

  a = 0;
  while ((core->champ = get_next_line(fd)))
    {
      a = 5;
      if (my_strncmp(NAME_CMD_STRING, core->champ, 5) == 0)
	name_string(core, a, fd_create);
      else if (my_strncmp(COMMENT_CMD_STRING, core->champ, 8) == 0)
	comment_string(core, p, fd_create);
    }
}

int		main(int argc, char **argv)
{
  t_core	*core;
  int		p;
  int		n;
  int		fd;
  int		fd_create;

  p = 9;
  n = 0;
  if (argc != 2 || check_file(argv) != 0 ||
      (core = malloc(sizeof(t_core)) + 5) == NULL ||
      (core->cor = malloc(1000)) == NULL)
    return (2);
  while (argv[1][n] != '.')
    {
      core->cor[n] = argv[1][n];
      n++;
    }
  if ((fd_create = open(my_strcat(core->cor, ".cor"),
			O_CREAT | O_RDWR | O_TRUNC, 436)) < 0)
    return (my_putstr_error("open error\n"));
  if ((fd = open(argv[1], O_RDONLY)) < 0)
    return (my_putstr_error("open error\n"));
  my_putchar_fd(0x00, fd_create);
  read_file(core, fd, p, fd_create);
  return (0);
}
