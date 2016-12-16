/*
** my_strlen.c for  in /home/rectoria/delivery/Projets/Projet_my_sokoban
** 
** Made by Bastien
** Login   <rectoria@epitech.net>
** 
** Started on  Thu Dec 15 13:14:19 2016 Bastien
** Last update Thu Dec 15 13:38:40 2016 Bastien
*/

#include <unistd.h>

void	my_putstr(char *str)
{
  int	i;

  i = -1;
  while (str[++i])
    write(1, &str[i], 1);
}

int	my_strlen(char *str)
{
  int	i;
  int	k;

  k = 0;
  i = -1;
  while (str[++i])
    k++;
  k -= 1;
  return (k);
}
