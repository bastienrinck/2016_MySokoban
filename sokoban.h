/*
** sokoban.h for  in /home/rectoria/delivery/Projets/Projet_my_sokoban
** 
** Made by Bastien
** Login   <rectoria@epitech.net>
** 
** Started on  Wed Dec 14 09:00:07 2016 Bastien
** Last update Mon Dec 19 18:20:39 2016 Bastien
*/

#ifndef MY_SOKOBAN_H_
# define MY_SOKOBAN_H_

typedef struct	s_tab
{
  char	**tmap;
  char	**save;
  int	width;
  int	height;
}t_tab;

typedef struct	s_player
{
  int	y;
  int	x;
}t_player;

typedef struct	s_winfo
{
  int	y;
  int	x;
}t_winfo;

char	*my_memset(int, int);
int	get_size(char *);
char	**malloc_fct(int, int, char **);
char	**malloc_tmap(t_tab *, char **, char *);
void	put_map(char **, char *, int);
t_tab	*str_to_t_tab(char *);
void	free_t_tab(t_tab *);
void	display(t_tab *, char **, t_winfo);
void	victory(t_tab *, t_player *);
int	check_status(t_tab *, t_player *);
void	check_hole(t_tab *, t_player *);
void	move_p(char **, t_player *, int, int);
void	move_up(t_tab *, char **, t_player *);
void	move_down(t_tab *, char **, t_player *);
void	move_left(t_tab *, char **, t_player *);
void	move_right(t_tab *, char **, t_player *);
void	find_player(char **, t_player *);
void	my_reset(char **, char **, t_player *);
void	check_nbelem(t_tab *, t_player *);
void	check_arg(t_tab *, t_player *);
int	my_strlen(char *);
void	free_t_tab(t_tab *);
void	free_and_err(t_tab *, t_player *);
void	my_putstr(char *);
int	check_around(char **, int, int);
void	display(t_tab *, char **, t_winfo);
void	usage();
void	isamap(char);
void	check_border(t_tab *, t_player *, int, int);
void	check_player(t_tab *, t_player *);

#endif /* !MY_SOKOBAN_H_ */
