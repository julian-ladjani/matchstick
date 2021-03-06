/*
** main.c for matchstick in /home/julian-ladjani/delivery/CPE/Matchstick/CPE_2016_matchstick/src
** 
** Made by julian ladjani
** Login   <julian.ladjani@epitech.net>
** 
** Started on  Thu Feb 23 16:14:44 2017 julian ladjani
** Last update Fri Feb 24 12:13:12 2017 julian ladjani
*/

#include "matchstick.h"

int		main(int ac, char **av)
{
  t_game	game;

  if (verif_args(ac, av) < 0)
    return (0);
  game = make_game(my_getnbr(av[1]), my_getnbr(av[2]));
  if (game.map == NULL || game.line == NULL)
    return (0);
  return (play_matchstick(&game));
}
