##
## EPITECH PROJECT, 2022
## my_radar
## File description:
## Makefile
##

NAME	=		my_radar

CFLAGS	= 		-W -Wall -Wextra

SRC		=		./src/main.c					\
				./src/data_grab.c				\
				./src/data_grab_sec.c			\
				./src/my_strlen.c				\
				./src/plane_related.c			\
				./src/tower_related.c			\
				./src/graphic_part.c			\
				./src/sprites_init.c			\
				./src/moving_sprite.c			\
				./src/collision.c				\
				./src/text.c					\
				./src/division_screen.c			\

OBJ		=		$(SRC:.c=.o)

CSFML	=		-lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

MATH 	=		-lm

all:	$(OBJ)
		gcc $(OBJ) -o $(NAME) $(CFLAGS) $(CSFML) $(MATH) -g3

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re:	fclean all
