# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/14 09:40:45 by kdi-noce          #+#    #+#              #
#    Updated: 2022/05/06 17:12:56 by kdi-noce         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= philo
C		= clang
CFLAG	= -Wall -Wextra -Werror -g3 -fsanitize=address
SRC		= philo.c usec.c pilo.c
OBJ		= $(SRC:.c=.o)

all: 	  $(NAME)

$(NAME):  $(SRC)
		  $(C) $(CFLAG) $(SRC) -o $(NAME) && time ./$(NAME)

clean:

fclean:   
		  rm $(NAME)

re:		  fclean all
