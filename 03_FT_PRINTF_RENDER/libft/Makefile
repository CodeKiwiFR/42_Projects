# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhotting <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 14:28:05 by mhotting          #+#    #+#              #
#    Updated: 2023/12/18 16:50:33 by mhotting         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# GENERAL
NAME			=	libft.a
CC				=	cc
CFLAGS			=	-Wall -Werror -Wextra

# HEADERS
HEADERS_DIR		=	./
HEADERS_FILES	=	libft.h
HEADERS			=	$(addprefix $(HEADERS_DIR), $(HEADERS_FILES))

# STRING
STRING_FILES	=	ft_atoi.c ft_isalnum.c ft_isalpha.c ft_isascii.c			\
					ft_isspace.c ft_isdigit.c ft_isprint.c ft_itoa.c			\
					ft_putchar_fd.c	ft_putendl_fd.c	ft_putnbr_fd.c				\
					ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c			\
					ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c		\
					ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c			\
					ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c			\
					ft_toupper.c ft_ctoa.c ft_get_long_len.c ft_ltoa.c			\
					ft_ltoa_base.c ft_get_ulong_len.c ft_ultoa_base.c			\
					ft_is_valid_base.c ft_atol.c ft_atoul.c ft_prepend_chars.c	\
					ft_append_chars.c

# MEMORY
MEMORY_FILES	=	ft_bzero.c ft_calloc.c ft_memchr.c ft_memcmp.c ft_memcpy.c	\
					ft_memmove.c ft_memset.c

# LIST
LIST_FILES		=	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c			\
					ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c		\
					ft_lstnew.c ft_lstsize.c

# SOURCES
SRCS			=	$(STRING_FILES) $(MEMORY_FILES) $(LIST_FILES)

# OBJECTS
OBJS_MAIN_DIR	=	objs/
OBJS_FILES		=	$(SRCS:.c=.o)
OBJS			=	$(addprefix $(OBJS_MAIN_DIR), $(OBJS_FILES))

#################################################

# RULES
all: $(NAME)

$(NAME): $(OBJS_MAIN_DIR) $(OBJS)
	ar -rcs $(NAME) $(OBJS)

$(OBJS_MAIN_DIR)%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@ -I$(HEADERS_DIR)

$(OBJS_MAIN_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJS_MAIN_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
