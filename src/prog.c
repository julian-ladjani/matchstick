/*
** prog.c for matchstick in /home/julian-ladjani/delivery/CPE/Matchstick/CPE_2016_matchstick
** 
** Made by julian ladjani
** Login   <julian.ladjani@epitech.net>
** 
** Started on  Thu Feb 23 16:13:17 2017 julian ladjani
** Last update Sun Feb 26 14:54:15 2017 julian ladjani
*/

#include "matchstick.h"

int	ia_turn(t_game *game)
{
  my_putstr("\nAI's turn...\n", 1);
  xor_ia(game);
  return (game->nbstick);
}

int	play_matchstick(t_game *game)
{
  int	value;

  write_map(game);
  while (42)
    {
      if ((value = my_turn(game)) == 0)
	{
	  my_putstr("You lost, too bad...\n", 1);
	  return (0);
	}
      else if (value == -1)
	{
	  return (0);
	}
      else if ((value = ia_turn(game)) == 0)
	{
	  my_putstr("I lost... snif... but I'll get you next time!!\n", 1);
	  return (1);
	}
    }
  return (84);
}
