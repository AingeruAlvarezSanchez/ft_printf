# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalvarez <aalvarez@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/28 13:18:39 by aalvarez          #+#    #+#              #
#    Updated: 2021/08/06 11:05:34 by aalvarez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c flags_1.c flags_2.c

NAME = libftprintf.a

OBJS_DIR = objs/
OBJS = $(SRCS:.c=.o)
OBJECTS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))

CC = gcc

CFLAGS = -Wall -Werror -Wextra

$(OBJS_DIR)%.o : %.c ft_printf.h
	@mkdir -p $(OBJS_DIR)
	@gcc $(CC_FLAGS) -c $< -o $@

$(NAME): $(OBJECTS_PREFIXED)
	@ar r $(NAME) $(OBJECTS_PREFIXED)

all: $(NAME)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
