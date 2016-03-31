# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zzeller <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/13 15:34:09 by zzeller           #+#    #+#              #
#*   Updated: 2016/03/26 14:31:14 by juthomas         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

.SUFFIXES:

NAME = fillit

SRC = fillit.c	\
	  list.c	\
	  errors.c	\
	  \
	  \

OBJ = fillit.o	\
	  list.o	\
	  errors.c	\
	  \
	  \

H = ./fillit.h

all:
	gcc -Wall -Werror -Wextra -c $(SRC) -I $(H)
	gcc -Wall -Werror -Wextra $(OBJ) -o $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
