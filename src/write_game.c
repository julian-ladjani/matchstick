/*
** write_game.c for matchstick in /home/julian-ladjani/delivery/CPE/Matchstick/CPE_2016_matchstick
** 
** Made by julian ladjani
** Login   <julian.ladjani@epitech.net>
** 
** Started on  Mon Feb 20 12:57:18 2017 julian ladjani
** Last update Sun Feb 26 15:06:28 2017 julian ladjani
*/

#include "matchstick.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str, int output)
{
  int	i;

  i = 0;
  output = 1;
  while (str[i++] != '\0');
  i--;
  write(output, str, i);
}

void	write_map(t_game *game)
{
  int	i;

  i = 0;
  while (i < (game->maxlenght + 2))
    {
      my_putchar('*');
      i++;
    }
  my_putchar('\n');
  i = 0;
  while (game->map[i] != NULL)
    {
      my_putchar('*');
      my_putstr(game->map[i], 1);
      my_putchar('*');
      my_putchar('\n');
      i++;
    }
  i = 0;
  while (i++ < (game->maxlenght + 2))
    my_putchar('*');
  my_putchar('\n');
}

void	write_play(int nbstick, int line, t_game *game, int type)
{
  if (type == 1)
    my_putstr("Player removed \0", 1);
  else
    my_putstr("AI removed \0", 1);
  my_putstr(my_putnbr(nbstick), 1);
  my_putstr(" match(es) from line \0", 1);
  my_putstr(my_putnbr(line), 1);
  my_putstr("\n\0", 1);
  write_map(game);
}
