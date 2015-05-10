/*
** my.h for my.h in /home/chouqu_d/rendu/Projet/MUL_2014_fdf
** 
** Made by gregory chouquet
** Login   <chouqu_d@epitech.net>
** 
** Started on  Sun Dec  7 23:34:40 2014 gregory chouquet
<<<<<<< HEAD
** Last update Sat Apr 11 15:52:38 2015 Amlan BARUA
=======
** Last update Sat Apr 11 14:38:48 2015 michael besnainou
>>>>>>> 9d58746a15e3fb8d374dc9b36b24eb64c642b19e
*/

#ifndef MY_H_
# define MY_H_

#define			NAME	" : name = "
#define			COMMENT	"comment = "

typedef struct		s_vm
{
  int			fd;
  int			ret;
  char			buffer;
  char			*champ;
  char			*cor;
  char			str[130];
  int			i;
  int			j;
  int			a;
  unsigned char		*memory;
}			t_vm;

typedef struct		s_core
{
  char			*champ;
  char			*cor;
}			t_core;

int			my_getnbr(char *str);
int			my_strlen(char *str);
int			my_putstr(char *str);
int			my_putstr_error(char *str);
void			my_put_nbr(int nb);
void			my_putchar(char c);
int			my_strncmp(char *s1, char *s2, int n);
int			my_put_nbr_base(unsigned int nb, char *base);
int			read_champ(t_vm *vm, int argc, char **argv);
void			my_putchar_fd(char c, int fd_create);
char			*get_next_line(const int fd);
char			*my_strcat(char *dest, char *src);
int			alloc_mem(t_vm *vm);
void			fill_tab(t_vm *vm, int argc);
void			get_header(t_vm *vm);
void			cycle();

#endif /* !MY_H_ */
