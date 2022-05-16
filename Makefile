# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dino <dino@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/14 09:40:45 by kdi-noce          #+#    #+#              #
#    Updated: 2022/05/14 18:39:12 by dino             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= 	philo
PRINTF	=	./printf/libftprintf.a
C		= 	clang
CC		=	gcc
CFLAG	= 	-Wall -Wextra -g3 -fsanitize=address
RM		= 	rm -rf
SRC		= 	philo_main.c \
			fct_annex.c
#OBJ	= 	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(SRC) $(PRINTF)
#			$(C) $(CFLAG) $(SRC) -o $(NAME)
			$(CC) $(CFLAG) $(SRC) $(PRINTF) -o $(NAME)
		
exec:		./time $(NAME)

$(PRINTF):
			make -C printf
delet:		
			$(RM) philo.dSYM
			$(RM) .DS_Store

clean:
			make -C printf clean

fclean:   
			rm -f $(NAME)
			make -C $(PRINTF) fclean

re:			fclean all
