/*
** menu.c for my_sokoban in /home/rectoria/delivery/Projets/Projet_my_sokoban/PSU_2016_my_sokoban/bonus
** 
** Made by Bastien
** Login   <rectoria@epitech.net>
** 
** Started on  Tue Dec 20 14:33:56 2016 Bastien
** Last update Tue Dec 20 17:40:21 2016 Bastien
*/

#include <unistd.h>
#include <curses.h>
#include "sokoban.h"

void	logo()
{
  mvprintw(20, COLS/2 - 28, "%s",
	   " ____     ___    _  __   ___    ____       _      _   _ ");
  mvprintw(21, COLS/2 - 28, "%s",
	   "/ ___|   / _ \\  | |/ /  / _ \\  | __ )     / \\    | \\ | |");
  mvprintw(22, COLS/2 - 28, "%s",
	   "\\___ \\  | | | | | ' /  | | | | |  _ \\    / _ \\   |  \\| |");
  mvprintw(23, COLS/2 - 28, "%s",
	   " ___) | | |_| | | . \\  | |_| | | |_) |  / ___ \\  | |\\  |");
  mvprintw(24, COLS/2 - 28, "%s",
	   "|____/   \\___/  |_|\\_\\  \\___/  |____/  /_/   \\_\\ |_| \\_|");
}

void		disp_menu2(int selected)
{
  clear();
  logo();
  mvprintw(8, COLS/2 - 3, "%s", "Resume");
  mvprintw(10, COLS/2 - 6, "%s", "Restart map");
  mvprintw(12, COLS/2 - 2, "%s", "Exit");
  if (selected == 0)
    mvprintw(8, COLS/2 - 6, "%s", "->");
  else if (selected == 1)
    mvprintw(10, COLS/2 - 9, "%s", "->");
  else if (selected == 2)
    mvprintw(12, COLS/2 - 5, "%s", "->");
}

void		disp_menu1(int selected)
{
  clear();
  logo();
  mvprintw(8, COLS/2 - 4, "%s", "New game");
  mvprintw(10, COLS/2 - 2, "%s", "Exit");
  if (selected == 0)
    mvprintw(8, COLS/2 - 7, "%s", "->");
  else if (selected == 1)
    mvprintw(10, COLS/2 - 5, "%s", "->");
}

void		menu1(t_tab *tmap, t_player *player, t_game *ginfo)
{
  int		ch;
  int		selected;

  selected = 0;
  while (1)
    {
      disp_menu1(selected);
      ch = getch();
      if (ch == KEY_UP)
	selected = (selected > 0) ? selected - 1 : selected;
      else if (ch == KEY_DOWN)
	selected = (selected < 1) ? selected + 1 : selected;
      else if (ch == 32)
	{
	  if (selected == 0)
	    {
	      init_ginfo(ginfo);
	      clear();
	      return ;
	    }
	  if (selected == 1)
	    free_and_ex(tmap, player);
	}
    }
}

void	menu2_space(t_tab *tmap, t_player *player, int selected, t_game *ginfo)
{
  if (selected == 0)
    return ;
  if (selected == 1)
    {
      my_reset(tmap->tmap, tmap->save, player);
      init_ginfo(ginfo);
      return ;
    }
  if (selected == 2)
    free_and_ex(tmap, player);
}

void		menu2(t_tab *tmap, t_player *player, t_game *ginfo)
{
  int	ch;
  int	selected;

  selected = 0;
  while (1)
    {
      disp_menu2(selected);
      ch = getch();
      if (ch == KEY_UP)
	selected = (selected > 0) ? selected - 1 : selected;
      else if (ch == KEY_DOWN)
	selected = (selected < 2) ? selected + 1 : selected;
      else if (ch == 32)
	{
	  menu2_space(tmap, player, selected, ginfo);
	  return ;
	}
    }
}
