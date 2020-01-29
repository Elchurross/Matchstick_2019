##
## EPITECH PROJECT, 2019
## makefile for compil with change name exe
## File description:
## final makefile
##

SRC         =       main.c \
					lib.c \
					plain_map.c \
					while.c \
					check_win.c\
					ia.c \
					stick.c \
					usefull_fonction.c \
					monte_carlo.c \
					my_strdup.c \
					my_strlen.c \
					fonction_attribute.c

OBJ         =             $(SRC:.c=.o)

NAME        =             matchstick

CC            =             gcc

CFLAGS    +=            -W -Wall -Wextra -g3



all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) 

clean:
	@rm -f $(OBJ)

fclean:		clean
	@rm -f $(NAME)

re: fclean all
