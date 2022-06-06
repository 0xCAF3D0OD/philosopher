# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dino <dino@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/14 09:40:45 by kdi-noce          #+#    #+#              #
#    Updated: 2022/06/03 23:09:25 by dino             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	philo
PRINTF_DIR	=	printf
PRINTF		= 	$(PRINTF_DIR)/libftprintf.a
C			= 	clang
CC			=	gcc
CFLAG		= 	-Wall -Wextra -Wextra -fsanitize=address -g3

RM			= 	rm -rf
SRC			= 	philosopher.c	\
				thread_mutex.c	\
				check_fcts.c	\
				print_philos.c	\
				time_philo.c	\
				fct_annex.c		\
				

#philo_main.c \
			
#OBJ	= 	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(SRC) $(PRINTF)
#			$(C) $(CFLAG) $(SRC) -o $(NAME)
			$(CC) $(CFLAG) $(SRC) $(PRINTF) -o $(NAME)
		
exec:		./time $(NAME)

$(PRINTF):
			make -C $(PRINTF_DIR)
delet:		
			$(RM) philo.dSYM
			$(RM) .DS_Store

clean:
			make -C $(PRINTF_DIR) clean

fclean:   
			rm -f $(NAME)
			make -C $(PRINTF_DIR) fclean

re:			fclean all
