/*
** fonc1.c for matchstick in /home/julian-ladjani/delivery/CPE/Matchstick/CPE_2016_matchstick/src
** 
** Made by julian ladjani
** Login   <julian.ladjani@epitech.net>
** 
** Started on  Tue Feb 21 18:53:47 2017 julian ladjani
** Last update Fri Feb 24 13:26:09 2017 julian ladjani
*/

#include "matchstick.h"

int	my_getnbr(char *str)
{
  int	digit;
  int	counter;

  digit = 0;
  counter = 0;
  while (*str >= '0' && *str <= '9' && *str != '\0')
    {
      digit = digit * 10;
      digit = digit + *str - 48;
      str++;
      counter++;
    }
  return (digit);
}

char	*my_putnbr(int nb)
{
  int	i;
  char	*result;

  if ((result = malloc(sizeof(nb) * sizeof(char) + 1)) == NULL)
    return (NULL);
  i = -1;
  while (nb > 0)
    {
      result[++i] = ((nb % 10) + 48);
      nb /= 10;
    }
  result[++i] = '\0';
  my_revstrprintf(result);
  return (result);
}

int	verif_line(char *line, t_game *game)
{
  int	nbline;

  if (line == NULL)
    return (-1);
  if (my_str_isnum(line, 1) == 0)
    return (-1);
  nbline = my_getnbr(line) - 1;
  if (nbline > game->nbline || nbline < 0)
    {
      my_putstr("Error: this line is out of range\n", 2);
      return (-1);
    }
  return (0);
}

int	verif_stick(char *stick, char *line, t_game *game)
{
  int	nbline;
  int	nbstick;

  if (stick == NULL || line == NULL)
    return (-1);
  if (my_str_isnum(stick, 1) == 0)
    return (-1);
  nbline = my_getnbr(line) - 1;
  nbstick = my_getnbr(stick);
  return (verif_stick2(nbstick, nbline, game));
}

void	take_stick(int nbstick, int line, t_game *game, int type)
{
  char	*cline;
  int	i;
  int	stick;

  stick = nbstick;
  cline = game->map[line];
  i = game->maxlenght;
  game->nbstick -= nbstick;
  game->line[line] -= nbstick;
  game->linebase[line] = my_getlnbr(my_convertbase(game->line[line], 2, "01"));
  while (i > 0 && nbstick > 0)
    {
      if (cline[i] == '|')
	{
	  cline[i] = ' ';
	  nbstick--;
	}
      i--;
    }
  write_play(stick, line + 1, game, type);
}
