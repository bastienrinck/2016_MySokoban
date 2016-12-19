/*
** str_to_wordtab.c for my_sokoban in /home/rectoria/delivery/Projets/Projet_my_sokoban
** 
** Made by Bastien
** Login   <rectoria@epitech.net>
** 
** Started on  Mon Dec 12 10:15:44 2016 Bastien
** Last update Fri Dec 16 01:15:32 2016 Bastien
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "sokoban.h"

int	get_size(char *pathname)
{
  int	fd;
  int	size;
  char	buf;

  size = 0;
  fd = open(pathname, O_RDONLY);
  while (read(fd, &buf, 1) != 0)
    size += 1;
  close(fd);
  return (size);
}

char	**malloc_fct(int line, int largest, char **tmap)
{
  int	count;

  count = -1;
  if ((tmap = malloc(sizeof(char *) * (line + 1))) == NULL)
    return (NULL);
  while (++count < line)
    {
      if ((tmap[count] = malloc(sizeof(char) * largest + 1)) == NULL)
	return (NULL);
    }
  return (tmap);
}

char	**malloc_tmap(t_tab *tab, char **tmap, char *map)
{
  int	largest;
  int	i;
  int	count;
  int	line;

  line = 0;
  i = 0;
  largest = 0;
  while (map[i++])
    {
      count = 1;
      while (map[i] != '\n' && map[i] != '\0')
	{
	  count++;
	  i++;
	}
      largest = (largest < count) ? count : largest;
      line++;
    }
  tmap = malloc_fct(line, largest, tmap);
  tab->width = largest;
  tab->height = line;
  return (tmap);
}

void	put_map(char **tmap, char *map, int size)
{
  int	i;
  int	j;
  int	k;

  i = -1;
  j = 0;
  while (++i < size)
    {
      k = 0;
      while (map[i] != '\n' && i < size)
	{
	  tmap[j][k] = map[i];
	  k++;
	  i++;
	}
      tmap[j][k] = '\0';
      j++;
    }
  tmap[j] = NULL;
}

t_tab	*str_to_t_tab(char *pathname)
{
  int	size;
  int	fd;
  char	*map;
  t_tab	*tmap;

  if ((tmap = malloc(sizeof(t_tab))) == NULL)
    return (NULL);
  size = get_size(pathname);
  map = my_memset('0', size);
  fd = open(pathname, O_RDONLY);
  read(fd, map, size);
  close(fd);
  tmap->tmap = malloc_tmap(tmap, tmap->tmap, map);
  tmap->save = malloc_tmap(tmap, tmap->save, map);
  put_map(tmap->tmap, map, size);
  put_map(tmap->save, map, size);
  free(map);
  return (tmap);
}
