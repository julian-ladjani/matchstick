##
## Makefile for Project in /home/shielder/Projects/
##
## Made by Maxime PICOT
## Login   <shielder@epitech.net>
##
## Started on  Mon Nov 21 09:49:22 2016 Maxime PICOT
## Last update Sun Feb 26 05:52:08 2017 julian ladjani
##

COMP	=	gcc

SRC	=	src/fonc1.c		\
		src/fonc2.c		\
		src/ia_foncs.c		\
		src/ia_foncs2.c		\
		src/get_next_line.c	\
		src/prog.c		\
		src/prog2.c		\
		src/write_game.c	\
		src/make_game1.c	\
		src/make_game2.c	\
		src/main.c		

CFLAGS	=	-I./include/ -Wall -Wextra -g

LDLIBS	=	-L./lib/

LDFLAGS	=	

OBJ	=	$(SRC:src/%.c=obj/%.o)

RM	=	rm -f

NAME	=	matchstick

all:		$(NAME)

$(NAME):	$(OBJ)
		$(COMP) -o $(NAME) $(OBJ)  $(LDLIBS) $(LDFLAGS)

obj/%.o:	src/%.c
		@mkdir -p obj/
		$(COMP) -o $@ -c $< $(CFLAGS)

clean:
		$(RM) $(OBJ)
		$(RM) -rf obj/

fclean: 	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
