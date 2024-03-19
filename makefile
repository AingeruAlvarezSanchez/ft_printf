NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Werror -Wextra
SANITIZE_FLAGS = -fsanitize=address -fsanitize=leak

SRC = src/ft_printf.c
OBJ = $(patsubst src/%.c, obj/%.o, $(SRC))

INCLUDE = -I./inc

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ)
	$(AR) rcs $(NAME) $^

$(OBJ): $(SRC)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

.PHONY: clean
clean:
	$(RM) -r obj

.PHONY: fclean
fclean: clean
	$(RM) $(NAME)

.PHONY: re
re: fclean all

.PHONY: sanitize
sanitize: CFLAGS := $(SANITIZE_FLAGS)
sanitize: all
