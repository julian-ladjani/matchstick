/*
** ia_foncs2.c for matchstick in /home/julian-ladjani/delivery/CPE/Matchstick/CPE_2016_matchstick
** 
** Made by julian ladjani
** Login   <julian.ladjani@epitech.net>
** 
** Started on  Sun Feb 26 04:28:42 2017 julian ladjani
** Last update Sun Feb 26 06:11:45 2017 julian ladjani
*/

#include "matchstick.h"

void    xor_ia(t_game *game)
{
  int   line;
  int   stick;

  line = search_best_line(game);
  stick = 1;
  if (game->nzline == 1 && game->maxtake >= (game->line[line] - 1)
      && game->line[line] > 1)
    {
      stick = game->line[line] - 1;
    }
  else if (game->maxtake >= game->line[line] && (game->nzline % 2) != 0
	   && game->nzline > 1)
    {
      ia_case2(game, &line, &stick);
    }
  else
    {
      ia_case3(game, &line, &stick);
    }
  take_stick(stick, line, game, 0);
}

void	ia_case2(t_game *game, int *tline, int *tstick)
{
  int	line;
  int	stick;
  int	end;

  line = 1;
  stick = *tstick;
  end = 0;
  while (check_line_withedit(game, line, game->line[line]) == 0 && end == 0)
    {
      line++;
      if (line >= game->nbline)
	{
	  end = 1;
	  line = search_best_line(game);
	}
      stick = game->line[line];
      if (end == 1)
	ia_case3(game, tline, tstick);
    }
  if (end == 0)
    {
      *tline = line;
      *tstick = stick;
    }
}

void    ia_case3(t_game *game, int *tline, int *tstick)
{
  int	line;
  int	stick;

  line = *tline;
  stick = *tstick;
  if (game->nbline % 2 == 0)
    stick = game->line[line];
  while (check_line_withedit(game, line, stick) == 0
	 && stick <= game->line[line] && stick < game->maxtake
	 && stick > 0)
    {
      if (game->nbline % 2 == 0)
	stick--;
      else
	stick++;
    }
  if (stick > game->line[line])
    stick = game->line[line];
  if (stick <= 0)
    stick = 1;
  *tline = line;
  *tstick = stick;
}
