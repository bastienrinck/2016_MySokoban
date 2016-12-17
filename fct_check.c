/*
** fct_check.c for  in /home/rectoria/delivery/Projets/Projet_my_sokoban
** 
** Made by Bastien
** Login   <rectoria@epitech.net>
** 
** Started on  Wed Dec 14 23:09:20 2016 Bastien
** Last update Sat Dec 17 18:23:04 2016 Bastien
*/

#include <stdio.h>
#include <stdlib.h>
#include "sokoban.h"

void	check_nbelem(t_tab *tmap, t_player *player)
{
  int	elem;
  int	i;
  int	j;

  i = -1;
  elem = 0;
  while (tmap->tmap[++i] != NULL)
    {
      j = -1;
      while (tmap->tmap[i][++j] != '\0')
	{
	  elem = (tmap->tmap[i][j] == 'O') ? elem + 1 : elem;
	  elem = (tmap->tmap[i][j] == 'X') ? elem - 1 : elem;
	}
    }
  if (elem != 0)
    free_and_err(tmap, player);
}

int	check_around(char **tab, int y, int x)
{
  int	i;

  i = 0;
  i = ((tab[y-1][x] == 'X' || tab[y-1][x] == '#') &&
       (tab[y][x+1] == 'X' || tab[y][x+1] == '#')) ? 1 : i;
  i = ((tab[y][x+1] == 'X' || tab[y][x+1] == '#') &&
       (tab[y+1][x] == 'X' || tab[y+1][x] == '#')) ? 1 : i;
  i = ((tab[y+1][x] == 'X' || tab[y+1][x] == '#') &&
       (tab[y][x-1] == 'X' || tab[y][x-1] == '#')) ? 1 : i;
  i = ((tab[y][x-1] == 'X' || tab[y][x-1] == '#') &&
       (tab[y-1][x] == 'X' || tab[y-1][x] == '#')) ? 1 : i;
  return (i);
}

void	check_box(t_tab *tmap, t_player *player, int nb)
{
  int	i;
  int	j;
  int	k;

  i = -1;
  k = 1;
  while (tmap->tmap[++i] != NULL)
    {
      j = -1;
      while (tmap->tmap[i][++j] != '\0')
	if (tmap->tmap[i][j] == 'X')
	  k = (check_around(tmap->tmap, i, j) == 0) ? 0 : k;
    }
  if (k == 1 && nb == 0)
    free_and_err(tmap, player);
  if (k == 1 && nb == 1)
    defeat(tmap, player);
}

void	check_ascii(t_tab *tmap, t_player *player)
{
  int	i;
  int	j;

  i = -1;
  while (tmap->tmap[++i] != NULL)
    {
      j = -1;
      while (tmap->tmap[i][++j] != '\0')
	if (tmap->tmap[i][j] != 'X' && tmap->tmap[i][j] != 'O' &&
	    tmap->tmap[i][j] != '#' && tmap->tmap[i][j] != 'P' &&
	    tmap->tmap[i][j] != ' ')
	  free_and_err(tmap, player);
    }
}

void	check_arg(t_tab *tmap, t_player *player)
{
  check_ascii(tmap, player);
  check_nbelem(tmap, player);
  check_box(tmap, player, 0);
}
