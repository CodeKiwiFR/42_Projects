# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhotting <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/23 18:17:04 by mhotting          #+#    #+#              #
#    Updated: 2023/08/30 19:01:39 by mhotting         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	bsq
CC		= 	cc
CFLAGS	+= 	-Wall -Wextra -Werror
INC_DIR	=	./includes
HEADERS	=	$(INC_DIR)/bsq.h
SRCS	=	./srcs/main.c				\
			./srcs/maps_utils.c			\
			./srcs/solver.c				\
			./srcs/matrix_generator.c	\
			./srcs/utils.c				\
			./srcs/utils2.c				\
			./srcs/memory_cleaner.c		\
			./srcs/stdin_reader.c		\
			./srcs/get_file_data.c		\
			./srcs/get_map_struct.c 	\
			./srcs/get_charset.c 		\
			./srcs/get_line_cnt.c 		\
			./srcs/checkers.c
OBJS	=	$(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -I$(INC_DIR)

all: $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INC_DIR)
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
