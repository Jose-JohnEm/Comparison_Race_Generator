SRC		=	src/main.cpp 					\
			src/parsor.cpp					\
			src/my_lib.cpp					\
			src/window.cpp					\

CLASS	=	src/classes/company.cpp			\
			src/classes/hud.cpp				\
			src/classes/specs.cpp			\

CC		=	g++

SFLAGS	=	-lsfml-graphics -lsfml-window -lsfml-system -lm



CFLAGS	=	-I./include -g3

OBJ		=	$(SRC) $(CLASS)

NAME	=	CRG

all:
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(SFLAGS)

clean:
	echo CLEAN

fclean: clean
	rm -f $(NAME)
	echo FCLEAN

re:	fclean all
	echo RE
