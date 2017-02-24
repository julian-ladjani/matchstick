/*
** fonc2.c for matchstick in /home/julian-ladjani/delivery/CPE/Matchstick/CPE_2016_matchstick/src
** 
** Made by julian ladjani
** Login   <julian.ladjani@epitech.net>
** 
** Started on  Fri Feb 24 04:56:11 2017 julian ladjani
** Last update Fri Feb 24 13:08:29 2017 julian ladjani
*/

#include "matchstick.h"

char	*my_revstrprintf(char *str)
{
  int	c;
  int	c2;
  char	strtemp;

  c = 0;
  c2 = 0;
  while (str[c] != '\0')
    c++;
  c--;
  while (c > c2)
    {
      strtemp = str[c2];
      str[c2] = str[c];
      str[c] = strtemp;
      c2++;
      c--;
    }
  return (str);
}

int	my_str_isnum(char *str, int type)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i] != '\0')
    {
      if (str[i] < 48 || str[i] > 57)
	{
	  if (type == 1)
	    my_putstr("Error: invalid input (positive number expected)\n", 2);
	  return (0);
	}
      i++;
    }
  if (i == 0)
    {
      if (type == 1)
	my_putstr("Error: invalid input (positive number expected)\n", 2);
      return (0);
    }
  return (1);
}

long	my_getlnbr(char *str)
{
  long	digit;
  long	counter;

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

int	verif_stick2(int nbstick, int nbline, t_game *game)
{
  if (nbstick <= 0)
    {
      my_putstr("Error: you have to remove at least one match\n", 2);
      return (-1);
    }
  else if (nbstick > game->maxtake)
    {
      my_putstr("Error: you cannot remove more than ", 2);
      my_putstr(my_putnbr(game->maxtake), 2);
      my_putstr(" matches per turn\n", 2);
      return (-2);
    }
  else if (nbstick > game->line[nbline])
    {
      my_putstr("Error: not enough matches on this line\n", 2);
      return (-3);
    }
  return (0);
}
