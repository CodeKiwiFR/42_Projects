# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhotting <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/23 18:17:04 by mhotting          #+#    #+#              #
#    Updated: 2023/08/24 21:12:49 by mhotting         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	do-op
CC		= 	cc
CFLAGS	+= 	-Wall -Wextra -Werror
INC_DIR	=	./includes
HEADERS	=	$(INC_DIR)/ft.h
SRCS	=	./srcs/main.c	\
			./srcs/ops.c	\
			./srcs/utils.c	\
			./srcs/utils2.c
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
