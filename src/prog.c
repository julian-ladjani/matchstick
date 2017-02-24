/*
** prog.c for matchstick in /home/julian-ladjani/delivery/CPE/Matchstick/CPE_2016_matchstick
** 
** Made by julian ladjani
** Login   <julian.ladjani@epitech.net>
** 
** Started on  Thu Feb 23 16:13:17 2017 julian ladjani
** Last update Fri Feb 24 14:15:30 2017 julian ladjani
*/

#include "matchstick.h"

int	my_turn(t_game *game)
{
  char	*line;
  char	*stick;

  line = NULL;
  stick = NULL;
  my_putstr("\nYour turn:\n", 1);
  while (verif_line(line, game) < 0)
    {
      if (line != NULL)
	free(line);
      my_putstr("Line: ", 1);
      while ((line = get_next_line(0)) == NULL);
    }
  while	(verif_stick(stick, line, game) < 0)
    {
      if (stick != NULL)
	free(stick);
      my_putstr("Matches: ", 1);
      while ((stick = get_next_line(0)) == NULL);
    }
  take_stick(my_getnbr(stick), my_getnbr(line) - 1, game, 1);
  free(stick);
  free(line);
  return (game->nbstick);
}

int	ia_turn(t_game *game)
{
  my_putstr("\nAI's turn...\n", 1);
  xor_ia(game);
  return (game->nbstick);
}

int	play_matchstick(t_game *game)
{
  write_map(game);
  while (42)
    {
      if (my_turn(game) == 0)
	return (0);
      else if (ia_turn(game) == 0)
	return (1);
    }
  return (84);
}
