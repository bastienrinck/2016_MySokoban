##
## Makefile for sokoban in /home/rectoria/delivery/Projets/Projet_my_sokoban
## 
## Made by Bastien
## Login   <rectoria@epitech.net>
## 
## Started on  Fri Dec 16 01:16:08 2016 Bastien
## Last update Tue Dec 20 16:00:24 2016 Bastien
##

CC	=	gcc

RM	=	rm -f

NAME	=	my_sokoban

SRCS	=	fct_check.c \
		fct_action.c \
		fct_free.c \
		fct_lib.c \
		fct_move.c \
		fct_random.c \
		my_sokoban.c \
		str_to_tab.c \
		fct_game.c \
		menu.c

OBJS	=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) -lncurses

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
