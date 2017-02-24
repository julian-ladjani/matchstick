/*
** matchstick.h for matchstick in /home/julian-ladjani/delivery/CPE/Matchstick/CPE_2016_matchstick/include
** 
** Made by julian ladjani
** Login   <julian.ladjani@epitech.net>
** 
** Started on  Tue Feb 21 18:38:22 2017 julian ladjani
** Last update Fri Feb 24 16:05:43 2017 julian ladjani
*/

#ifndef MATCHSTICK_H_
# define MATCHSTICK_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

# define READ_SIZE 256

typedef struct	s_game
{
  char		**map;
  int		*line;
  long		*linebase;
  int		maxlenght;
  int		nbstick;
  int		nbline;
  int		maxtake;
}		t_game;

void		take_stick(int nbstick, int line, t_game *game, int type);
void		my_putchar(char c);
void		my_putstr(char *str, int output);
void		write_map(t_game *game);
void		write_play(int nbstick, int line, t_game *game, int type);
void		xor_ia(t_game *game);

char		*my_revstrprintf(char *str);
char		*my_convertbase(unsigned int number, int base, char *baseconf);
char		*my_putnbr(int nb);
char		*get_next_line(const int fd, int *end);
char		**make_map(int  nbline, int maxlenght);

int		verif_args(int ac, char **av);
int		search_best_line(t_game *game);
int		check_line_base(t_game *game);
int		check_line_withedit(t_game *game, int line, int stick);
int		check_somme(int somme);
int		my_str_isnum(char *str, int type);
int		verif_line(char *line, t_game *game);
int		verif_stick(char *stick, char *line, t_game *game);
int		verif_stick2(int nbstick, int nbline, t_game *game);
int		calc_maxlenght(int nbline);
int		my_getnbr(char *str);
int		my_turn(t_game *game);
int		ia_turn(t_game *game);
int		play_matchstick(t_game *game);
int		*create_line(int nbline, int *nbstick);

long		my_getlnbr(char *str);
long		*create_line_base(int *line, int nbline);

t_game		make_game(int nbline, int maxtake);

#endif /* !MATCHSTICK_H_ */
