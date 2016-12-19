/*
** fct_game.c for sokoban in /home/rectoria/delivery/Projets/Projet_my_sokoban/PSU_2016_my_sokoban/bonus
** 
** Made by Bastien
** Login   <rectoria@epitech.net>
** 
** Started on  Mon Dec 19 13:35:01 2016 Bastien
** Last update Mon Dec 19 18:20:52 2016 Bastien
*/

#include <time.h>
#include "sokoban.h"

void	check_border(t_tab *tmap, t_player *player, int y, int x)
{
  if (y <= 0 || y >= tmap->height || x <= 0 || x >= my_strlen(tmap->tmap[y]))
    free_and_err(tmap, player);
  tmap->tmap[y][x] = '1';
  if (tmap->tmap[y - 1][x] != '#' && tmap->tmap[y - 1][x] != '1')
    check_border(tmap, player, y - 1, x);
  if (tmap->tmap[y + 1][x] != '#' && tmap->tmap[y + 1][x] != '1')
    check_border(tmap, player, y + 1, x);
  if (tmap->tmap[y][x - 1] != '#' && tmap->tmap[y][x - 1] != '1')
    check_border(tmap, player, y, x -1);
  if (tmap->tmap[y][x + 1] != '#' && tmap->tmap[y][x + 1] != '1')
    check_border(tmap, player, y, x + 1);
}

void	check_player(t_tab *tmap, t_player *player)
{
  int	i;
  int	j;
  int	p;

  i = -1;
  p = 0;
  while (tmap->tmap[++i] != NULL)
    {
      j = -1;
      while (tmap->tmap[i][++j] != '\0')
	p = (tmap->tmap[i][j] == 'P') ? p + 1 : p;
    }
  if (p != 1)
    free_and_err(tmap, player);
}
