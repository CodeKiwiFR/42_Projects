# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhotting <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/23 18:17:04 by mhotting          #+#    #+#              #
#    Updated: 2023/08/23 21:13:05 by mhotting         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
CC		=	gcc
CFLAGS	+=	-Wall -Wextra -Werror -I$(INC_DIR)
INC_DIR	=	includes
HEADERS	=	./includes/ft.h
SRCS	=	./srcs/ft_putchar.c	\
			./srcs/ft_swap.c	\
			./srcs/ft_putstr.c	\
			./srcs/ft_strlen.c	\
			./srcs/ft_strcmp.c
OBJS	=	$(SRCS:.c=.o)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

all: $(NAME)

%.o: %.c $(HEADERS)
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
