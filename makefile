NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Werror -Wextra
SANITIZE_FLAGS = -fsanitize=address -fsanitize=leak

SRC = src/ft_printf.c
OBJ = $(patsubst src/%.c, obj/%.o, $(SRC))

INCLUDE = -I./inc -I./libft

.PHONY: all
all: submodules $(NAME)

$(NAME): $(OBJ)
	$(AR) rcs $(NAME) $^

$(OBJ): $(SRC)
	$(MAKE) ext -C libft
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -L libft -lft $(INCLUDE) -c $< -o $@

.PHONY: clean
clean:
	$(MAKE) clean -C libft
	$(RM) -r obj

.PHONY: fclean
fclean: clean
	$(MAKE) fclean -C libft
	$(RM) $(NAME)

.PHONY: re
re: fclean all
	$(MAKE) re -C libft

.PHONY: sanitize
sanitize: CFLAGS := $(SANITIZE_FLAGS)
sanitize: all

submodules:
	git submodule update --init --recursive
