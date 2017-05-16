##
## Makefile for make in /home/barbe_j/rendu/Projet_2015/CPE_2014_Pushswap/radix
## 
## Made by jordan barbé
## Login   <barbe_j@epitech.net>
## 
## Started on  Fri Apr 15 19:55:08 2016 jordan barbé
## Last update Thu Aug 11 14:18:53 2016 jordan barbé
##

NAME		= bsq

CC		= gcc -g3

RM		= rm -rf

SRC		= main.c		\
		  get_next_line.c	\
		  my_algo.c		\
		  basic.c		\
		  print_result.c	\
		  basic_next.c

OBJ		= $(SRC:.c=.o)

##CFLAGS		= -Wall -Werror -ansi -pedantic

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
