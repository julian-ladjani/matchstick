/*
** ia_foncs.c for matchstick in /home/julian-ladjani/delivery/CPE/Matchstick/CPE_2016_matchstick/src
** 
** Made by julian ladjani
** Login   <julian.ladjani@epitech.net>
** 
** Started on  Fri Feb 24 04:34:09 2017 julian ladjani
** Last update Fri Feb 24 15:36:34 2017 julian ladjani
*/

#include "matchstick.h"

void	xor_ia(t_game *game)
{
  int	line;
  int	stick;

  line = search_best_line(game);
  if (game->line[line] < game->maxtake)
    stick = game->line[line];
  else
    stick = game->maxtake;
  while (check_line_withedit(game, line, stick) == 0 && stick > 1)
    {
      stick--;
    }
  take_stick(stick, line, game, 0);
}

int	search_best_line(t_game *game)
{
  int	i;
  int	linestick;
  int	line;

  i = 0;
  linestick = 0;
  line = 0;
  while(i < game->nbline)
    {
      if (game->line[i] > linestick)
	{
	  linestick = game->line[i];
	  line = i;
	}
      i++;
    }
  return (line);
}

int	check_line_base(t_game *game)
{
  long	somme;
  int	i;

  somme = 0;
  i = 0;
  while	(i < game->nbline)
    {
      somme += game->linebase[i];
      i++;
    }
  return (check_somme(somme));
}

int	check_line_withedit(t_game *game, int line, int stick)
{
  long  somme;
  int   i;

  somme = 0;
  i = 0;
  if (stick == 0)
    return (0);
  while (i < game->nbline)
    {
      if (i == line)
	somme += my_getlnbr(my_convertbase(game->line[i] - stick, 2, "01"));
      else
	somme += game->linebase[i];
      i++;
    }
  return (check_somme(somme));
}

int	check_somme(int somme)
{
  int	i;
  char	*tempsum;
  int	chiffre;

  i = 0;
  if ((tempsum = my_putnbr(somme)) == NULL)
    return (0);
  while (tempsum[i] != '\0')
    {
      chiffre = tempsum[i] - 48;
      if (chiffre % 2 != 0)
	{
	  free(tempsum);
	  return (1);
	}
      i++;
    }
  free(tempsum);
  return (0);
}
