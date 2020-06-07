##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##


SRC		=	src/main.cpp 					\
			src/parsor.cpp					\
			src/my_error.cpp				\

CLASS	=	src/classes/company.cpp			\

SFLAGS	=	-lsfml-graphics -lsfml-window -lsfml-system -lm

NAME	=	CRG

CFLAGS	=	-I ./include/ -g3

all:
	g++ $(CFLAGS) -o $(NAME) $(SRC) $(CLASS) $(SFLAGS)

clean:
	echo CLEAN

fclean: clean
	rm -f $(NAME)
	echo FCLEAN

re:	fclean all
	echo RE
