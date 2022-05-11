# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/14 09:40:45 by kdi-noce          #+#    #+#              #
#    Updated: 2022/05/11 15:52:40 by kdi-noce         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= 	philo
C		= 	clang
CC		=	gcc
CFLAG	= 	-Wall -Wextra -Werror -g3 -fsanitize=address
RM		= 	rm -r
SRC		= 	philo.c \
			fct_annex.c
#OBJ	= 	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(SRC)
#			$(C) $(CFLAG) $(SRC) -o $(NAME)
			$(CC) $(CFLAG) $(SRC) -o $(NAME) && $(RM) philo.dSYM
		
exec:		./time $(NAME)

clean:

fclean:   
			rm -f $(NAME)

re:			fclean all
