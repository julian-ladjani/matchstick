/*
** make_map.c for matchstick in /home/julian-ladjani/delivery/CPE/Matchstick/CPE_2016_matchstick/src
** 
** Made by julian ladjani
** Login   <julian.ladjani@epitech.net>
** 
** Started on  Tue Feb 21 19:14:57 2017 julian ladjani
** Last update Sun Feb 26 04:44:27 2017 julian ladjani
*/

#include "matchstick.h"

int		calc_maxlenght(int nbline)
{
  int		maxlenght;

  maxlenght = 1;
  while (nbline > 1)
    {
      maxlenght += 2;
      nbline--;
    }
  return (maxlenght);
}

char		**make_map(int	nbline, int maxlenght)
{
  char		**map;
  int		i;
  int		j;

  i = 0;
  if ((map = malloc((nbline + 1) * sizeof(char *))) == NULL)
    return (NULL);
  while (i < nbline)
    {
      j = 0;
      if ((map[i] = malloc((maxlenght + 1) * sizeof(char))) == NULL)
	return (NULL);
      while (j < maxlenght)
	{
	  if (j >= ((maxlenght / 2) - i) && j <= ((maxlenght / 2) + i))
	    map[i][j] = '|';
	  else
	    map[i][j] = ' ';
	  j++;
	  map[i][j] = '\0';
	}
      i++;
    }
  map[i] = NULL;
  return (map);
}

int		*create_line(int nbline, int *nbstick)
{
  int		i;
  int		*line;
  int		stick;

  i = 0;
  stick = 1;
  if ((line = malloc((nbline + 1) * sizeof(int))) == NULL)
    return (NULL);
  while (i < nbline)
    {
      line[i] = stick;
      stick += 2;
      *nbstick += line[i];
      i++;
    }
  line[i] = -1;
  return (line);
}

t_game		make_game(int nbline, int maxtake)
{
  t_game	game;

  game.maxtake = maxtake;
  game.nbline = nbline;
  game.nzline = nbline;
  game.maxlenght = calc_maxlenght(nbline);
  game.map = make_map(nbline, game.maxlenght);
  game.nbstick = 0;
  game.line = create_line(nbline, &game.nbstick);
  game.linebase = create_line_base(game.line, nbline);
  return (game);
}
