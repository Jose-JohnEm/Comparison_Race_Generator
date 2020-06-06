##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##


MAIN	=	main.cpp 					\

CFLAGS	=	-I./include/

SFLAGS	=	-lsfml-graphics -lsfml-window -lsfml-system -lm

OBJ		= 	$(MAIN:.cpp=.o)				\

NAME	=	CRG

all:	$(OBJ)
	g++ -o $(NAME) $(OBJ) $(CFLAGS) $(SFLAGS)

clean:
	rm -f $(OBJ)
	echo CLEAN

fclean: clean
	rm -f $(NAME)
	echo FCLEAN

re:	fclean all
	echo RE
