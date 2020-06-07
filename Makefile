##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##


SRC		=	src/main.cpp 					\
			src/parsor.cpp					\
			src/my_error.cpp				\
			src/mylib.cpp					\

SFLAGS	=	-lsfml-graphics -lsfml-window -lsfml-system -lm

NAME	=	CRG

CFLAGS	=	-I ./include/

all:
	g++ $(CFLAGS) -o $(NAME) $(SRC) $(SFLAGS)

clean:
	echo CLEAN

fclean: clean
	rm -f $(NAME)
	echo FCLEAN

re:	fclean all
	echo RE
