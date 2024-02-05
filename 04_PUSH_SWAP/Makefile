# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhotting <mhotting@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/02 20:48:41 by mhotting          #+#    #+#              #
#    Updated: 2024/02/05 16:40:31 by mhotting         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# GENERAL
NAME					=	push_swap
NAME_BONUS				=	checker
CC						=	cc
ifndef NOFLAGS
	CFLAGS				=	-Wall -Werror -Wextra
endif

# HEADERS
HEADERS_DIR				=	includes/
HEADERS_FILES			=	push_swap.h	\
							stack.h
HEADERS					=	$(addprefix $(HEADERS_DIR), $(HEADERS_FILES))
HEADERS_FILES_BONUS		=	checker_bonus.h
HEADERS_BONUS			=	$(addprefix $(HEADERS_DIR), $(HEADERS_FILES_BONUS))

# LIBFT
LIBFT_DIR				=	libft/
LIBFT_FILE				=	libft.a
LIBFT					=	$(addprefix $(LIBFT_DIR), $(LIBFT_FILE))
LIBFT_HEADERS_SUBDIR	=	includes/
LIBFT_HEADERS_DIR		=	$(addprefix $(LIBFT_DIR), $(LIBFT_HEADERS_SUBDIR))
LIBFT_HEADERS_FILE		=	libft.h
LIBFT_HEADERS			=	$(addprefix $(LIBFT_HEADERS_DIR), $(LIBFT_HEADERS_FILE))
LIBFT_FLAGS				=	-L$(LIBFT_DIR) -lft 

# SOURCES GENERAL
SRCS_MAIN_DIR			=	srcs/
SRCS_FILES				=	stack_utils1.c		\
							stack_utils2.c		\
							push_swap_utils1.c	\
							push_swap_utils2.c	\
							push_swap_utils3.c	\
							push_swap_utils4.c	\
							push_swap_utils5.c	\
							parser.c
SRCS					=	$(addprefix $(SRCS_MAIN_DIR), $(SRCS_FILES))

# SOURCES PUSH_SWAP
SRCS_FILES_PUSH_SWAP	=	push_swap.c			\
							intstack_utils.c	\
							cost_utils.c		\
							sort_utils1.c		\
							sort_utils2.c		\
							sort_utils3.c		\
							sort2_0.c			\
							sort2_1.c			\
							sort2_2.c			\
							sort2_3.c			\
							sort1.c
SRCS_PUSH_SWAP			=	$(addprefix $(SRCS_MAIN_DIR), $(SRCS_FILES_PUSH_SWAP))

# SOURCES CHECKER
SRCS_FILES_CHECKER		=	checker_bonus.c
SRCS_CHECKER			=	$(addprefix $(SRCS_MAIN_DIR), $(SRCS_FILES_CHECKER))

# OBJECTS GENERAL
OBJS_MAIN_DIR			=	objs/
OBJS_FILES				=	$(SRCS_FILES:.c=.o)
OBJS					=	$(addprefix $(OBJS_MAIN_DIR), $(OBJS_FILES))

# OBJECTS PUSH_SWAP
OBJS_FILES_PUSH_SWAP	=	$(SRCS_FILES_PUSH_SWAP:.c=.o)
OBJS_PUSH_SWAP			=	$(addprefix $(OBJS_MAIN_DIR), $(OBJS_FILES_PUSH_SWAP))

# OBJECTS CHECKER
OBJS_FILES_CHECKER		=	$(SRCS_FILES_CHECKER:.c=.o)
OBJS_CHECKER			=	$(addprefix $(OBJS_MAIN_DIR), $(OBJS_FILES_CHECKER))

#################################################

# RULES
all: $(NAME)

$(NAME): $(LIBFT) $(OBJS_MAIN_DIR) $(OBJS) $(OBJS_PUSH_SWAP)
	$(CC) $(CFLAGS) $(OBJS) $(OBJS_PUSH_SWAP) -I$(HEADERS_DIR) -I$(LIBFT_HEADERS_DIR) $(LIBFT_FLAGS) -o $@

$(OBJS_MAIN_DIR)%.o: $(SRCS_MAIN_DIR)%.c $(HEADERS) $(LIBFT_HEADERS)
	$(CC) $(CFLAGS) -I$(HEADERS_DIR) -I$(LIBFT_HEADERS_DIR) -c $< -o $@

$(OBJS_MAIN_DIR):
	mkdir -p $@

$(LIBFT): FORCE
	make -C $(LIBFT_DIR)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(LIBFT) $(OBJS_MAIN_DIR) $(OBJS) $(OBJS_CHECKER) $(HEADERS_BONUS)
	$(CC) $(CFLAGS) $(OBJS) $(OBJS_CHECKER) -I$(HEADERS_DIR) -I$(LIBFT_HEADERS_DIR) $(LIBFT_FLAGS) -o $@

FORCE:

clean:
	rm -rf $(OBJS_MAIN_DIR)

clean-libft:
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

fclean-libft:
	make -C $(LIBFT_DIR) fclean

ffclean: fclean fclean-libft

re: fclean all

rre: ffclean re

.PHONY: all clean fclean re clean-libft fclean-libft ffclean rre bonus
