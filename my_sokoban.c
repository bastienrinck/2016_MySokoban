/*
** my_sokoban.c for my_sokoban in /home/rectoria/delivery/Projets/Projet_my_sokoban
** 
** Made by Bastien
** Login   <rectoria@epitech.net>
** 
** Started on  Mon Dec 12 10:10:22 2016 Bastien
** Last update Fri Dec 16 00:46:24 2016 Bastien
*/

#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include "sokoban.h"

void	find_player(char **tmap, t_player *player)
{
  int	i;
  int	j;

  i = -1;
  while (tmap[++i] != NULL)
    {
      j = -1;
      while (tmap[i][++j] != '\0')
	if (tmap[i][j] == 'P')
	  {
	    player->y = i;
	    player->x = j;
	    return ;
	  }
    }
}

void	get_winfo(t_tab *tmap, t_winfo *winfo)
{
  const struct winsize element;

  ioctl(STDOUT_FILENO, TIOCGWINSZ, &element);
  winfo->y = (element.ws_row) / 2 - tmap->height / 2;
  winfo->x = (element.ws_col) / 2 - tmap->width / 2;
}

void	init_ncurses()
{
  initscr();
  noecho();
  curs_set(0);
  keypad(stdscr, TRUE);
}

void		sokoban(t_tab *tmap, t_player *player)
{
  int		ch;
  t_winfo	winfo;

  init_ncurses();
  while (check_status(tmap, player) == 0)
    {
      get_winfo(tmap, &winfo);
      display(tmap, tmap->tmap, winfo);
      ch = getch();
      if (ch == ' ')
	my_reset(tmap->tmap, tmap->save, player);
      else if (ch == KEY_UP)
	move_up(tmap, tmap->tmap, player);
      else if (ch == KEY_DOWN)
	move_down(tmap, tmap->tmap, player);
      else if (ch == KEY_LEFT)
	move_left(tmap, tmap->tmap, player);
      else if (ch == KEY_RIGHT)
	move_right(tmap, tmap->tmap, player);
      clear();
    }
}

int		main(int ac, char **av)
{
  t_tab		*tmap;
  int		result;
  t_player	*player;

  if (ac != 2)
    return (84);
  if (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0')
    usage();
  if ((player = malloc(sizeof(t_player))) == NULL)
    return (84);
  tmap = str_to_t_tab(av[1]);
  find_player(tmap->tmap, player);
  check_arg(tmap, player);
  sokoban(tmap, player);
  return (0);
}
