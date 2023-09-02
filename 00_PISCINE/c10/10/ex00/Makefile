# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhotting <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/23 18:17:04 by mhotting          #+#    #+#              #
#    Updated: 2023/08/23 22:09:19 by mhotting         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	ft_display_file
CC		= 	cc
CFLAGS	+= 	-Wall -Wextra -Werror
SRCS	=	./srcs/main.c
OBJS	=	$(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

all: $(NAME)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
