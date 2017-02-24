/*
** ia_foncs.c for matchstick in /home/julian-ladjani/delivery/CPE/Matchstick/CPE_2016_matchstick/src
** 
** Made by julian ladjani
** Login   <julian.ladjani@epitech.net>
** 
** Started on  Fri Feb 24 04:34:09 2017 julian ladjani
** Last update Fri Feb 24 14:14:14 2017 julian ladjani
*/

#include "matchstick.h"

void	xor_ia(t_game *game)
{
  /*long	somme;
  int	i;

  somme = 0;
  i = 0;
  while (i < nbline)
    {
      somme += game->linebase[i];
      i++;
      }*/
  int	i;

  i = 0;
  while (game->line[i++] == 0);
  take_stick(1, i, game, 0);
}
/*
int	check_line_base(t_game *game)
{
  long	somme;
  int	i;

  somme = 0;
  i = 0;
  while	(i < nbline)
    {
      somme += game->linebase[i];
      i++;
    }
  i = 0;
  
}

int	check_line_withedit(t_game *game, int line, int stick)
{
  long  somme;
  int   i;

  somme = 0;
  i = 0;
  while (i < nbline)
    {
      if (i == (line - 1))
      somme += game->linebase[i];
      i++;
    }
  i = 0;
}*/
