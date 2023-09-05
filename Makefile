# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdi-noce <kdi-noce@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/14 09:40:45 by kdi-noce          #+#    #+#              #
#    Updated: 2022/07/01 18:12:42 by kdi-noce         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= philo

PRINTF_DIR	= printf
PRINTF		= $(PRINTF_DIR)/libftprintf.a

CC		= gcc
CFLAG		= -Wall -Wextra -Wextra -Werror -g 
RM		= rm -rf
SRCS_DIR	= ./srcs/
SRC		= philosopher.c		\
		  thread_mutex.c	\
		  check_fcts.c		\
		  print_philos.c	\
		  time_philo.c		\
		  fct_annex.c		\
		  ft_routine.c		\
		  annexe.c
SRCS		= $(SRCS_DIR)*.c		

			
all: $(NAME)

$(NAME): $(SRCS) $(PRINTF)		
	$(CC) $(CFLAG) $(SRCS) $(PRINTF) -o $(NAME)
		
exec: ./time $(NAME)

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

re:	fclean all
