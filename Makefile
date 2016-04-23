# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zzeller <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/13 15:34:09 by zzeller           #+#    #+#              #
#    Updated: 2016/04/04 16:51:03 by zzeller          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

.SUFFIXES:

NAME = fillit

SRC = fillit.c	\
	  list.c	\
	  errors.c	\
	  write.c	\
	  list2.c	\
	  algo.c	\

OBJ = fillit.o	\
	  list.o	\
	  errors.o	\
	  write.o	\
	  list2.o	\
	  algo.o	\

H = ./fillit.h

$(NAME):
	gcc -Wall -Werror -Wextra -c $(SRC) -I $(H)
	gcc -Wall -Werror -Wextra $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
