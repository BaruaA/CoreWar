/*
** my_strlen.c for my_strlen.c in /home/besnai_m/rendu/C-Prog ELEM/CPE_2014_bsq/lib/my
** 
** Made by michael besnainou
** Login   <besnai_m@epitech.net>
** 
** Started on  Mon Jan 12 13:55:25 2015 michael besnainou
** Last update Sun Mar 22 14:59:56 2015 michael besnainou
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i = i + 1;
  return (i);
}
