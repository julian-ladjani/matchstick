/*
** prog2.c for matchstick in /home/julian-ladjani/delivery/CPE/Matchstick/CPE_2016_matchstick/src
** 
** Made by julian ladjani
** Login   <julian.ladjani@epitech.net>
** 
** Started on  Sun Feb 26 04:19:21 2017 julian ladjani
** Last update Sun Feb 26 06:11:05 2017 julian ladjani
*/

#include "matchstick.h"

int	my_turn(t_game *game)
{
  int	end;
  char	*line;
  char	*stick;

  line = NULL;
  stick = NULL;
  end = 0;
  my_putstr("\nYour turn:\n", 1);
  return (my_turn_loop(game, line, stick, end));
}

int	my_turn_loop(t_game *game, char *line, char *stick, int end)
{
  while (verif_line(line, game) < 0)
      {
	if (line != NULL)
	  free(line);
	my_putstr("Line: ", 1);
	while ((line = get_next_line(0, &end)) == NULL && end != 1);
	if (end == 1)
	  return (-1);
    }
  while (verif_stick(stick, line, game) < 0)
    {
      if (stick != NULL)
	free(stick);
      my_putstr("Matches: ", 1);
      while ((stick = get_next_line(0, &end)) == NULL && end != 1);
      if (end == 1)
	return (-1);
    }
  take_stick(my_getnbr(stick), my_getnbr(line) - 1, game, 1);
  free (stick);
  free (line);
  return (game->nbstick);
}
