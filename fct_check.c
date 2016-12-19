/*
** fct_check.c for  in /home/rectoria/delivery/Projets/Projet_my_sokoban
** 
** Made by Bastien
** Login   <rectoria@epitech.net>
** 
** Started on  Wed Dec 14 23:09:20 2016 Bastien
** Last update Mon Dec 19 18:17:40 2016 Bastien
*/

#include <stdio.h>
#include <stdlib.h>
#include "sokoban.h"

void	check_nbelem(t_tab *tmap, t_player *player)
{
  int	elem;
  int	i;
  int	j;
  int	box;
  int	hole;

  i = -1;
  elem = 0;
  box = 0;
  hole = 0;
  while (tmap->tmap[++i] != NULL)
    {
      j = -1;
      while (tmap->tmap[i][++j] != '\0')
	{
	  box = (tmap->tmap[i][j] == 'X') ? box + 1 : box;
	  hole = (tmap->tmap[i][j] == 'O') ? hole + 1 : hole;
	  elem = (tmap->tmap[i][j] == 'O') ? elem + 1 : elem;
	  elem = (tmap->tmap[i][j] == 'X') ? elem - 1 : elem;
	}
    }
  if (elem != 0 || box == 0 || hole == 0)
    free_and_err(tmap, player);
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
  check_border(tmap, player, player->y, player->x);
  my_reset(tmap->tmap, tmap->save, player);
  check_player(tmap, player);
  check_nbelem(tmap, player);
}
