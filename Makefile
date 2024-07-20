NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC = src/ft_printf.c \

OBJ = $(patsubst src/%.c, obj/%.o, $(SRC))
INC = -I inc/ -I Libft/

.PHONY: all
all: update_submodules $(NAME)

.PHONY: update_submodules
update_submodules:
	git submodule update --init --recursive

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

obj/%.o: src/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

.PHONY: clean
clean:
	rm -r obj/

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all
