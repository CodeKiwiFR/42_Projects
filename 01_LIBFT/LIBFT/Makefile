# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhotting <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 14:28:05 by mhotting          #+#    #+#              #
#    Updated: 2023/11/23 09:52:47 by mhotting         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# GENERAL
NAME			=	libft.a
CC				=	cc
CFLAGS			=	-Wall -Werror -Wextra

# HEADERS
HEADERS_DIR		=	includes/
HEADERS_FILES	=	libft.h
HEADERS			=	$(addprefix $(HEADERS_DIR), $(HEADERS_FILES))

# STRING
STRING_DIR		=	string/
STRING_FILES	=	ft_atoi.c ft_isalnum.c ft_isalpha.c ft_isascii.c			\
					ft_isspace.c ft_isdigit.c ft_isprint.c ft_itoa.c			\
					ft_putchar_fd.c	ft_putendl_fd.c	ft_putnbr_fd.c				\
					ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c			\
					ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c		\
					ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c			\
					ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c			\
					ft_toupper.c
STRING			=	$(addprefix $(STRING_DIR), $(STRING_FILES))

# MEMORY
MEMORY_DIR		=	memory/
MEMORY_FILES	=	ft_bzero.c ft_calloc.c ft_memchr.c ft_memcmp.c ft_memcpy.c	\
					ft_memmove.c ft_memset.c
MEMORY			=	$(addprefix $(MEMORY_DIR), $(MEMORY_FILES))

# LIST
LIST_DIR		=	list/
LIST_FILES		=	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c			\
					ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c		\
					ft_lstnew.c ft_lstsize.c
LIST			=	$(addprefix $(LIST_DIR), $(LIST_FILES))

# SOURCES
SRCS_MAIN_DIR	=	srcs/
SRCS_FILES		=	$(STRING) $(MEMORY) $(LIST)
SRCS_DIRS		=	$(STRING_DIR) $(MEMORY_DIR) $(LIST_DIR)
SRCS			=	$(addprefix $(SRCS_MAIN_DIR), $(SRCS_FILES))

# OBJECTS
OBJS_MAIN_DIR	=	objs/
OBJS_DIRS		=	$(addprefix $(OBJS_MAIN_DIR), $(SRCS_DIRS))
OBJS_ALL_DIRS	=	$(OBJS_MAIN_DIR) $(OBJS_DIRS)
OBJS_FILES		=	$(SRCS_FILES:.c=.o)
OBJS			=	$(addprefix $(OBJS_MAIN_DIR), $(OBJS_FILES))

#################################################

# RULES
all: $(NAME)

$(NAME): $(OBJS_ALL_DIRS) $(OBJS)
	ar -rcs $(NAME) $(OBJS)

$(OBJS_MAIN_DIR)%.o: $(SRCS_MAIN_DIR)%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@ -I$(HEADERS_DIR)

$(OBJS_ALL_DIRS):
	mkdir -p $@

clean:
	rm -rf $(OBJS_MAIN_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
