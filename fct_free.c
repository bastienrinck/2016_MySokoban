/*
** fct_free.c for sokoban in /home/rectoria/delivery/Projets/Projet_my_sokoban
** 
** Made by Bastien
** Login   <rectoria@epitech.net>
** 
** Started on  Thu Dec 15 13:24:12 2016 Bastien
** Last update Tue Dec 20 16:59:23 2016 Bastien
*/

#include <stdlib.h>
#include <stdio.h>
#include "sokoban.h"

void	free_t_tab(t_tab *tab)
{
  int	i;

  i = -1;
  while (tab->tmap[++i] != NULL)
    {
      free(tab->tmap[i]);
      free(tab->save[i]);
    }
  free(tab->tmap);
  free(tab->save);
  free(tab);
}

void	free_and_err(t_tab *tmap, t_player *player)
{
  free(player);
  free_t_tab(tmap);
  exit(84);
}
