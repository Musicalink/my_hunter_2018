##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## For infinadd
##

SRC_DIR=	$(realpath ./src)

LIB_DIR=	$(realpath ./lib/my)

INC_DIR=	$(realpath ./include)

SRC=		$(SRC_DIR)/generator.c\
			$(SRC_DIR)/event.c\
			$(SRC_DIR)/killer.c\
			$(SRC_DIR)/game.c\
			$(SRC_DIR)/main.c\

LIB=			my

OBJ=		$(SRC:.c=.o)

NAME=		my_hunter

#Arguments gcc
GCC_ARG=	-l csfml-window -l csfml-system -l csfml-graphics -l csfml-audio -L$(LIB_DIR) -l$(LIB) -I$(INC_DIR)
GCC_ARG_DEBUG=	-l csfml-window -l csfml-system -l csfml-graphics -l csfml-audio -L$(LIB_DIR) -l$(LIB) -I$(INC_DIR) -g

#Règles
all:		$(NAME)

$(NAME):
		make -C ./lib/my
		make clean -C ./lib/my
		gcc -o $(NAME) $(SRC) $(GCC_ARG)

debug:
		gcc -o $(NAME) $(SRC) $(GCC_ARG_DEBUG)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re: fclean all
