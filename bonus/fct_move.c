/*
** fct_move.c for sokoban in /home/rectoria/delivery/Projets/Projet_my_sokoban
** 
** Made by Bastien
** Login   <rectoria@epitech.net>
** 
** Started on  Wed Dec 14 13:19:37 2016 Bastien
** Last update Sun Dec 18 23:18:35 2016 Bastien
*/

#include "sokoban.h"

void	move_up(t_tab *tab, char **tmap, t_player *player)
{
  if (tmap[player->y-1][player->x] == '#' || player->y == 0 || player->y - 1 == 0 && tmap[player->y - 1][player->x] != ' ' && tmap[player->y - 1][player->x] != 'O')
    return ;
  else if (tmap[player->y - 1][player->x] == 'X' &&
	   tmap[player->y - 2][player->x]
	   != '#' && tmap[player->y - 2][player->x] != 'X')
    {
      tmap[player->y - 2][player->x] = 'X';
      tmap[player->y - 1][player->x] = 'P';
      tmap[player->y][player->x] = ' ';
      check_hole(tab, player);
    }
  else if (tmap[player->y - 1][player->x] != '#' &&
	   tmap[player->y - 1][player->x] != 'X')
    {
      move_p(tmap, player, player->y - 1, player->x);
      check_hole(tab, player);
    }
  find_player(tmap, player);
}

void	move_down(t_tab *tab, char **tmap, t_player *player)
{
  int	v;

  v = tab->height;
  if (tmap[player->y + 1][player->x] == '#' || player->y == v ||
      (player->y + 1 == v && tmap[player->y + 1][player->x] != ' ' && tmap[player->y + 1][player->x] != 'O'))
    return ;
  else if (tmap[player->y + 1][player->x] == 'X' &&
	   tmap[player->y + 2][player->x]
	   != '#' && tmap[player->y + 2][player->x] != 'X')
    {
      tmap[player->y + 2][player->x] = 'X';
      tmap[player->y + 1][player->x] = 'P';
      tmap[player->y][player->x] = ' ';
      check_hole(tab, player);
    }
  else if (tmap[player->y + 1][player->x] != '#' &&
	   tmap[player->y + 1][player->x] != 'X')
    {
      move_p(tmap, player, player->y + 1, player->x);
      check_hole(tab, player);
    }
  find_player(tmap, player);
}

void	move_left(t_tab *tab, char **tmap, t_player *player)
{
  if (tmap[player->y][player->x - 1] == '#' || player->x == 0 ||
      (player->x - 1 == 0 && tmap[player->y][player->x - 1] != ' ' && tmap[player->y][player->x - 1] != 'O'))
    return ;
  else if (tmap[player->y][player->x - 1] == 'X' &&
	   tmap[player->y][player->x - 2]
	   != '#' && tmap[player->y][player->x - 2] != 'X')
    {
      tmap[player->y][player->x - 2] = 'X';
      tmap[player->y][player->x - 1] = 'P';
      tmap[player->y][player->x] = ' ';
      check_hole(tab, player);
    }
  else if (tmap[player->y][player->x - 1] != '#' &&
	   tmap[player->y][player->x - 1] != 'X')
    {
      move_p(tmap, player, player->y, player->x - 1);
      check_hole(tab, player);
    }
  find_player(tmap, player);
}

void	move_right(t_tab *tab, char **tmap, t_player *player)
{
  int	v;

  v = my_strlen(tmap[player->y]);
  if (tmap[player->y][player->x + 1] == '#' || player->x == v ||
      (player->x + 1  == v && tmap[player->y][player->x] != ' ' && tmap[player->y][player->x + 1] != 'O'))
    return ;
  else if (tmap[player->y][player->x + 1] == 'X' &&
	   tmap[player->y][player->x + 2]
	   != '#' && tmap[player->y][player->x + 2] != 'X')
    {
      tmap[player->y][player->x + 2] = 'X';
      tmap[player->y][player->x + 1] = 'P';
      tmap[player->y][player->x] = ' ';
      check_hole(tab, player);
    }
  else if (tmap[player->y][player->x + 1] != '#' &&
	   tmap[player->y][player->x + 1] != 'X')
    {
      move_p(tmap, player, player->y, player->x + 1);
      check_hole(tab, player);
    }
  find_player(tmap, player);
}
