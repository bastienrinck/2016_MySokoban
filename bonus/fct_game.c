/*
** fct_game.c for sokoban in /home/rectoria/delivery/Projets/Projet_my_sokoban/PSU_2016_my_sokoban/bonus
** 
** Made by Bastien
** Login   <rectoria@epitech.net>
** 
** Started on  Mon Dec 19 13:35:01 2016 Bastien
** Last update Mon Dec 19 13:51:59 2016 Bastien
*/

#include <time.h>
#include "sokoban.h"

void	init_ginfo(t_game *ginfo)
{
  ginfo->push = 0;
  ginfo->move = 0;
  time(&ginfo->time);
}
