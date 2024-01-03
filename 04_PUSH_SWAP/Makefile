# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/02 20:48:41 by mhotting          #+#    #+#              #
#    Updated: 2024/01/03 01:02:55 by mhotting         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# GENERAL
NAME					=	push_swap
CC						=	cc
CFLAGS					=	-Wall -Werror -Wextra

# HEADERS
HEADERS_DIR				=	includes/
HEADERS_FILES			=	push_swap.h
HEADERS					=	$(addprefix $(HEADERS_DIR), $(HEADERS_FILES))

# LIBFT
LIBFT_DIR				=	libft/
LIBFT_FILE				=	libft.a
LIBFT					=	$(addprefix $(LIBFT_DIR), $(LIBFT_FILE))
LIBFT_HEADERS_SUBDIR	=	includes/
LIBFT_HEADERS_DIR		=	$(addprefix $(LIBFT_DIR), $(LIBFT_HEADERS_SUBDIR))
LIBFT_HEADERS_FILE		=	libft.h
LIBFT_HEADERS			=	$(addprefix $(LIBFT_HEADERS_DIR), $(LIBFT_HEADERS_FILE))
LIBFT_FLAGS				=	-L$(LIBFT_DIR) -lft 

# SOURCES
SRCS_MAIN_DIR			=	srcs/
SRCS_FILES				=	push_swap.c
SRCS					=	$(addprefix $(SRCS_MAIN_DIR), $(SRCS_FILES))

# OBJECTS
OBJS_MAIN_DIR			=	objs/
OBJS_FILES				=	$(SRCS_FILES:.c=.o)
OBJS					=	$(addprefix $(OBJS_MAIN_DIR), $(OBJS_FILES))

#################################################

# RULES
all: $(NAME)

$(NAME): $(LIBFT) $(OBJS_MAIN_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -I$(HEADERS_DIR) -I$(LIBFT_HEADERS_DIR) $(LIBFT_FLAGS) -o $(NAME)

$(OBJS_MAIN_DIR)%.o: $(SRCS_MAIN_DIR)%.c $(HEADERS) $(LIBFT_HEADERS)
	$(CC) $(CFLAGS) -I$(HEADERS_DIR) -I$(LIBFT_HEADERS_DIR) -c $< -o $@

$(OBJS_MAIN_DIR):
	mkdir -p $@

$(LIBFT): FORCE
	make -C $(LIBFT_DIR)

FORCE:

clean:
	rm -rf $(OBJS_MAIN_DIR)

clean-libft:
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)

fclean-libft:
	make -C $(LIBFT_DIR) fclean

ffclean: fclean fclean-libft

re: fclean all

.PHONY: all clean fclean re clean-libft fclean-libft ffclean
