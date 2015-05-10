/*
** get_next_line.h for get_next in /home/chouqu_d/rendu/CPE_2014_bsq
**
** Made by Gregory Chouquet
** Login   <chouqu_d@epitech.net>
**
** Started on  Sun Jan 18 23:55:14 2015 Gregory Chouquet
<<<<<<< HEAD
** Last update Sat Apr 11 13:25:18 2015 Amlan BARUA
=======
** Last update Sat Apr 11 13:26:45 2015 michael besnainou
>>>>>>> 9d58746a15e3fb8d374dc9b36b24eb64c642b19e
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_
# define	BUFFER_SIZE 10000

typedef struct	s_struct
{
  char		*line;
  int		n;
  int		f;
}		t_struct;

char		*get_next_line(const int fd);

#endif /* !GET_NEXT_LINE_H_ */
