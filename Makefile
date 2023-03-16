NAME = minishell

SRC =	src/main.c\
		src/init_shell.c\
		src/parsing.c\
		src/builtins.c \
		src/free.c\
		src/env.c\
		src/env_utils.c \
		src/echo.c\
		src/cd.c\
		src/export.c\
		src/exit.c\
		src/signal.c\
		src/command.c\
		src/export_utils.c\
		src/unset.c\
		src/pipe.c\
		src/sort_par.c\
		src/dollar.c\
		src/parsing_utils.c\

OBJ = $(SRC:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror -fsanitize=address -g

CPPFLAGS = -I/Users/${USER}/.brew/opt/readline/include

LIBFT = ./libft/libft.a

all: $(NAME)

$(NAME): $(SRC) $(OBJ) Includes/minishell.h
	@make -C ./libft
	$(CC) $(FLAGS) $(CPPFLAGS) $(SRC) $(LIBFT) -o $(NAME) -lreadline 

%.o: %.c
	$(CC) -c $(FLAGS) $(CPPFLAGS) $< -o $@

clean:
	rm -rf $(OBJ)
	make clean -C libft

fclean: clean
	rm -rf $(NAME)
	make fclean -C libft

re: fclean all

phony: fclean all re clean
