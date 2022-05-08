# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dino <dino@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/14 09:40:45 by kdi-noce          #+#    #+#              #
#    Updated: 2022/05/07 16:47:10 by dino             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= 	philo
C	= 	clang
CC	=	gcc
CFLAG	= 	-Wall -Wextra -g3 -fsanitize=address#-Werror -g3 -fsanitize=address
SRC	= 	philo.c fct_annex.c
OBJ	= 	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(SRC)
#		$(C) $(CFLAG) $(SRC) -o $(NAME)
		$(CC) $(CFLAG) $(SRC) -o $(NAME)

clean:

fclean:   
		rm -f $(NAME)

re:		fclean all
