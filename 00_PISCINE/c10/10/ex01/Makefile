# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhotting <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/23 18:17:04 by mhotting          #+#    #+#              #
#    Updated: 2023/08/24 15:11:48 by mhotting         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	ft_cat
CC		= 	cc
CFLAGS	+= 	-Wall -Wextra -Werror
INC_DIR	=	./includes
HEADERS	=	$(INC_DIR)/ft.h
SRCS	=	./srcs/main.c		\
			./srcs/utils.c		\
			./srcs/file_utils.c
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
