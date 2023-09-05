NAME = thread

OBJ_DIR = ./obj/
SRCS_DIR = ./srcs/

#------------ c++ -------------#
#CXX = g++
#CXXFLAG = -std=c++98 -Wall -Wextra -Werror

#SRCSX = $(SRCS_DIR)thread.cpp
#OBJSX = $(SRCSX:$(SRCS_DIR)%.cpp=$(OBJ_DIR)%.o

#------------ c ---------------#
CC = gcc
CFLAG = -Wall -Wextra -Werror

SRCS = $(SRCS_DIR)cThread/thread.c
OBJS = $(SRCS:$(SRCS_DIR)cThread/%.c=$(OBJ_DIR)%.o)

#------- compilation --------#
all: $(OBJ_DIR) $(OBJS) $(NAME)

$(OBJ_DIR):
	@mkdir -p $@

$(OBJ_DIR)%o: $(SRCS)
	$(CC) $(CFLAG) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAG) $^ -o $(NAME)
clean:
	rm -r $(OBJ_DIR)
	rm $(NAME)

fclean:
	rm $(NAME)

re: clean all
