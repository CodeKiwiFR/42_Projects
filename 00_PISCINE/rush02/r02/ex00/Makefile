# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhotting <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/23 18:17:04 by mhotting          #+#    #+#              #
#    Updated: 2023/08/27 22:32:51 by mhotting         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	rush-02
CC		= 	cc
CFLAGS	+= 	-Wall -Wextra -Werror
INC_DIR	=	./includes
HEADERS	=	$(INC_DIR)/ft.h
SRCS	=	./srcs/main.c				\
			./srcs/file_parsing.c		\
			./srcs/file_to_dict.c		\
			./srcs/file_to_dict2.c		\
			./srcs/key_value_cleaner.c	\
			./srcs/dict_checker.c		\
			./srcs/split.c				\
			./srcs/utils.c				\
			./srcs/utils2.c				\
			./srcs/utils3.c				\
			./srcs/utils_errors.c		\
			./srcs/clean_number.c		\
			./srcs/link_list.c			\
			./srcs/atoa.c				\
			./srcs/key_checker.c		\
			./srcs/translate.c			\
			./srcs/translate2.c
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
