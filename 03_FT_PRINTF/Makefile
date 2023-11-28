# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhotting <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/23 09:49:51 by mhotting          #+#    #+#              #
#    Updated: 2023/11/28 10:41:23 by mhotting         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# GENERAL
NAME			=	libftprintf.a
CC				=	cc
ifndef NOFLAGS
	CFLAGS		=	-Wall -Werror -Wextra
endif

# LIBFT
LIBFT_DIR		=	libft/
LIBFT_FILE		=	$(LIBFT_DIR)libft.a

# HEADERS
HEADERS_DIR		=	includes/
HEADERS_FILES	=	ft_printf.h
HEADERS			=	$(addprefix $(HEADERS_DIR), $(HEADERS_FILES))

# SOURCES
SRCS_DIR		=	srcs/
SRCS_FILES		=	ft_printf.c				\
					format_spec_utils.c
SRCS			=	$(addprefix $(SRCS_DIR), $(SRCS_FILES))

# OBJECTS
OBJS_DIR		=	objs/
OBJS_FILES		=	$(SRCS_FILES:.c=.o)
OBJS			=	$(addprefix $(OBJS_DIR), $(OBJS_FILES))

#################################################

# RULES
all: $(NAME)

$(NAME): $(LIBFT_FILE) $(OBJS_DIR) $(OBJS)
	cp $(LIBFT_FILE) $@
	ar -rcs $@ $(OBJS)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(HEADERS)
	$(CC) $(CFLAGS) -I$(HEADERS_DIR) -I$(LIBFT_DIR) -c $< -o $@

$(OBJS_DIR):
	mkdir -p $@

$(LIBFT_FILE): FORCE
	make -C $(LIBFT_DIR)

FORCE:

clean:
	rm -rf $(OBJS_DIR)

clean-libft:
	make -sC $(LIBFT_DIR) fclean

fclean: clean
	rm -f $(NAME)

ffclean: fclean clean-libft

re: fclean all

rre: ffclean all

.PHONY: all clean clean-libft fclean ffclean re rre FORCE
