# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhotting <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 16:46:15 by mhotting          #+#    #+#              #
#    Updated: 2023/11/06 17:51:18 by mhotting         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# GENERAL
NAME		=	libft_test
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra

# HEADERS
INC_DIR		=	./includes/
INC_FILES	=	libft_test.h
INCS		=	$(addprefix $(INC_DIR), $(INC_FILES))

# SOURCES
SRC_DIR		=	./srcs/
SRC_FILES	=	main.c
SRCS		=	$(addprefix $(SRC_DIR), $(SRC_FILES))

# OBJECTS
OBJ_DIR		=	./objs/
OBJ_FILES	=	$(SRC_FILES:.c=.o)
OBJS		=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))

# LIBRARY
LIBFT_DIR	=	./libft/
LIBFT_FILE	=	$(addprefix $(LIBFT_DIR), libft.a)
LIBFT_FLAGS	=	-L$(LIBFT_DIR) -lft

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -I$(INC_DIR) $(LIBFT_FLAGS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCS) $(LIBFT_FILE)
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INC_DIR) -I$(LIBFT_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT_FILE):
	make -sC $(LIBFT_DIR)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

clean-libft:
	make -sC $(LIBFT_DIR) fclean

ffclean: fclean clean-libft

re: fclean all

.PHONY: all clean fclean clean-libft ffclean re
