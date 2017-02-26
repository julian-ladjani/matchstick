/*
** make_game2.c for matchstick in /home/julian-ladjani/delivery/CPE/Matchstick/CPE_2016_matchstick
** 
** Made by julian ladjani
** Login   <julian.ladjani@epitech.net>
** 
** Started on  Thu Feb 23 15:47:04 2017 julian ladjani
** Last update Sun Feb 26 04:24:30 2017 julian ladjani
*/

#include "matchstick.h"

char		*my_convertbase(unsigned int number, int base, char *baseconf)
{
  unsigned int	number2;
  int		lenght;
  char		*snumber;

  lenght = 0;
  number2 = number;
  while (number2 != 0)
    {
      lenght++;
      number2 /= 2;
    }
  if ((snumber = malloc(lenght * sizeof(char) + 3)) == NULL)
    return (NULL);
  lenght = 0;
  while (number != 0)
    {
      snumber[lenght] = baseconf[number % base];
      number /= base;
      lenght++;
    }
  if (lenght == 0)
    snumber[lenght++] = baseconf[0];
  snumber[lenght] = '\0';
  my_revstrprintf(snumber);
  return (snumber);
}

int	verif_args(int ac, char **av)
{
  int	line;
  int	maxstick;

  if (ac < 3)
    return (-1);
  if (my_str_isnum(av[1], 0) == 0 || my_str_isnum(av[2], 0) == 0)
    return (-1);
  line = my_getnbr(av[1]);
  maxstick = my_getnbr(av[2]);
  if (line <= 0 || line > 100 || maxstick <= 0)
    return (-1);
  return (0);
}

long	*create_line_base(int *line, int nbline)
{
  int	i;
  long	*linebase;

  i = 0;
  if (line == NULL)
    return (NULL);
  if ((linebase = malloc((nbline + 1) * sizeof(long))) == NULL)
    return (NULL);
  while (i < nbline)
    {
      linebase[i] = my_getlnbr(my_convertbase(line[i], 2, "01"));
      i++;
    }
  linebase[i] = 9;
  return (linebase);
}
