# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhotting <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 16:46:15 by mhotting          #+#    #+#              #
#    Updated: 2023/11/21 11:16:34 by mhotting         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# GENERAL
NAME				=	libft_test
NAME_BONUS			=	libft_test_bonus
CC					=	cc
CFLAGS				=	-Wall -Werror -Wextra

# HEADERS
INC_DIR				=	./includes/
INC_FILES			=	libft_test.h
INCS				=	$(addprefix $(INC_DIR), $(INC_FILES))

# SOURCES
SRC_DIR				=	./srcs/
SRC_FILES			=	main.c				\
						utils.c				\
						test_isalpha.c		\
						test_isdigit.c		\
						test_isalnum.c		\
						test_isascii.c		\
						test_isprint.c		\
						test_strlen.c		\
						test_memset.c		\
						test_bzero.c		\
						test_memcpy.c		\
						test_memmove.c		\
						test_strlcpy.c		\
						test_strlcat.c		\
						test_toupper.c		\
						test_tolower.c		\
						test_strchr.c		\
						test_strrchr.c		\
						test_strncmp.c		\
						test_memchr.c		\
						test_memcmp.c		\
						test_strnstr.c		\
						test_atoi.c			\
						test_calloc.c		\
						test_strdup.c		\
						test_substr.c		\
						test_strjoin.c		\
						test_strtrim.c		\
						test_split.c		\
						test_itoa.c			\
						test_strmapi.c		\
						test_striteri.c		\
						test_putchar_fd.c	\
						test_putstr_fd.c	\
						test_putendl_fd.c	\
						test_putnbr_fd.c
SRCS				=	$(addprefix $(SRC_DIR), $(SRC_FILES))

# BONUS SOURCES
SRC_BONUS_DIR		=	./srcs/
SRC_BONUS_FILES		=	main_bonus.c				\
						utils.c						\
						test_bonus_lstadd_back.c	\
						test_bonus_lstadd_front.c	\
						test_bonus_lstclear.c		\
						test_bonus_lstdelone.c		\
						test_bonus_lstiter.c		\
						test_bonus_lstlast.c		\
						test_bonus_lstmap.c			\
						test_bonus_lstnew.c			\
						test_bonus_lstsize.c
SRCS_BONUS			=	$(addprefix $(SRC_BONUS_DIR), $(SRC_BONUS_FILES))

# OBJECTS
OBJ_DIR				=	./objs/
OBJ_FILES			=	$(SRC_FILES:.c=.o)
OBJS				=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))

# BONUS OBJECTS
OBJ_BONUS_DIR		=	./objs_bonus/
OBJ_BONUS_FILES		=	$(SRC_BONUS_FILES:.c=.o)
OBJS_BONUS			=	$(addprefix $(OBJ_BONUS_DIR), $(OBJ_BONUS_FILES))

# LIBRARY
LIBFT_DIR			=	./libft/
LIBFT_INC_DIR		=	./libft/includes/
LIBFT_FILE			=	$(addprefix $(LIBFT_DIR), libft.a)
LIBFT_FLAGS			=	-L$(LIBFT_DIR) -lft


# RULES
all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -I$(INC_DIR) $(LIBFT_FLAGS) -lbsd

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS_DIR) $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAME_BONUS) -I$(INC_DIR) $(LIBFT_FLAGS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCS) $(LIBFT_FILE)
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INC_DIR) -I$(LIBFT_INC_DIR)

$(OBJ_BONUS_DIR)%.o: $(SRC_BONUS_DIR)%.c $(INCS) libft-bonus
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INC_DIR) -I$(LIBFT_INC_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_BONUS_DIR):
	mkdir -p $(OBJ_BONUS_DIR)

$(LIBFT_FILE):
	make -sC $(LIBFT_DIR)

libft-bonus:
	make -sC $(LIBFT_DIR) bonus

clean:
	rm -rf $(OBJ_DIR) $(OBJ_BONUS_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

clean-libft:
	make -sC $(LIBFT_DIR) fclean

ffclean: fclean clean-libft

re: fclean all

rre: ffclean all

.PHONY: all clean fclean clean-libft ffclean re rre
