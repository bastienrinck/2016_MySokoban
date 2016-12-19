/*
** fct_random.c for sokoban in /home/rectoria/delivery/Projets/Projet_my_sokoban
** 
** Made by Bastien
** Login   <rectoria@epitech.net>
** 
** Started on  Thu Dec 15 23:03:32 2016 Bastien
** Last update Mon Dec 19 16:43:58 2016 Bastien
*/

#include <stdlib.h>
#include <stdio.h>
#include <curses.h>
#include <time.h>
#include "sokoban.h"

void	my_reset(char **dest, char **src, t_player *player)
{
  int	i;
  int	j;

  i = -1;
  while (src[++i] != NULL)
    {
      j = -1;
      while (src[i][++j] != '\0')
	dest[i][j] = src[i][j];
      dest[i][j] = '\0';
    }
  find_player(dest, player);
}

char	*my_memset(int c, int nb)
{
  int	i;
  char	*str;

  i = -1;
  if ((str = malloc(sizeof(char) * nb + 1)) == NULL)
    return (NULL);
  while (++i < nb)
    {
      str[i] = c;
    }
  str[i] = '\0';
  return (str);
}

void	usage()
{
  my_putstr("USAGE\n\t./my_sokoban map\n\nDESCRIPTION\n\tmap\tfile ");
  my_putstr("representing the warehouse map, containing '#' for ");
  my_putstr("walls,\n\t\t'P' for the player, 'X' for boxes and '0' ");
  my_putstr("for storage locations.\n");
  exit(0);
}

void	display(t_tab *tmap, char **tab, t_winfo winfo, t_game *ginfo)
{
  int		i;
  int		y;
  long int	timing;

  if (tmap->width > winfo.x * 2 + tmap->width / 2 ||
      tmap->height > winfo.y * 2 + tmap->height / 2)
    {
      mvprintw(LINES/2, COLS/2 - 10, "%s", "Enlarge the terminal");
      return ;
    }
  y = winfo.y;
  i = -1;
  while (tab[++i] != NULL)
    {
      mvprintw(y, winfo.x, "%s", tab[i]);
      y++;
    }
  time(&timing);
  mvprintw(y + 1, winfo.x, "move : %i  pushs : %i  time : %d",
	   ginfo->move, ginfo->push, timing - ginfo->time);
}

void	isamap(char c)
{
  if (c != 'X' && c != 'O' && c != '#' && c != ' ' &&
      c != 'P' && c != '\0' && c != '\n')
    exit(84);
}
