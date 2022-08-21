# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/12 16:35:10 by kdi-noce          #+#    #+#              #
#    Updated: 2021/11/24 21:30:43 by kdi-noce         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a 
CC = gcc
FLAGS = -Wall -Wextra -Werror
OPTION = -c
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

.c.o : ${CC} ${FLAGS} -c $< -o ${<:.c=.0}

all: $(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	/bin/rm -f $(OBJ)
fclean: clean
	/bin/rm -f $(NAME)
	

re: fclean all

.PHONY: clean fclean re all
