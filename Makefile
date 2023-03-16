# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcaron <jcaron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/09 11:17:47 by jcaron            #+#    #+#              #
#    Updated: 2023/03/13 23:11:00 by jcaron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR		=	./src/

SRC			=	$(SRC_DIR)export2.c			\
				$(SRC_DIR)unset.c			\
				$(SRC_DIR)exit.c			\
				$(SRC_DIR)export1.c			\
				$(SRC_DIR)cd2.c				\
				$(SRC_DIR)env.c				\
				$(SRC_DIR)echo.c			\
				$(SRC_DIR)cd1.c				\
				$(SRC_DIR)pwd.c				\
				$(SRC_DIR)browser.c			\
				$(SRC_DIR)command1.c		\
				$(SRC_DIR)redirection1.c	\
				$(SRC_DIR)builtin_exec.c	\
				$(SRC_DIR)redirection2.c	\
				$(SRC_DIR)pipe.c			\
				$(SRC_DIR)conditions.c		\
				$(SRC_DIR)command2.c		\
				$(SRC_DIR)utils.c			\
				$(SRC_DIR)init.c			\
				$(SRC_DIR)main.c			\
				$(SRC_DIR)verification_1.c	\
				$(SRC_DIR)verification_2.c	\
				$(SRC_DIR)eval_variables.c	\
				$(SRC_DIR)tk_vector_1.c		\
				$(SRC_DIR)lexer.c			\
				$(SRC_DIR)node_2.c			\
				$(SRC_DIR)eval_heredoc.c	\
				$(SRC_DIR)command_1.c		\
				$(SRC_DIR)tk_vector.c		\
				$(SRC_DIR)get_heredoc.c		\
				$(SRC_DIR)lexer_2.c			\
				$(SRC_DIR)lexer_1.c			\
				$(SRC_DIR)command.c			\
				$(SRC_DIR)node.c			\
				$(SRC_DIR)node_1.c			\
				$(SRC_DIR)node_3.c			\
				$(SRC_DIR)token.c			\
				$(SRC_DIR)tk_vector_2.c	

BIN_DIR		=	./bin/

INC_D		=	./include/

OBJ 		=	$(SRC:$(SRC_DIR)%.c=$(BIN_DIR)%.o)

CC			=	clang

CFLAG		=	-Wall -Wextra -Werror

NAME		=	minishell

LIBFT		=	./libft/libft.a


all: $(NAME)

$(BIN_DIR)%.o : $(SRC_DIR)%.c
	@$(CC) $(CFLAG) -I$(INC_D) -I./libft -c $< -o $@
	@echo "***compilation of '$<' in '$@'***"

$(LIBFT):
	make -C libft

$(BIN_DIR) :
	@mkdir -p $(BIN_DIR)

$(NAME): $(LIBFT) $(BIN_DIR) $(OBJ)
	@clang $(CFLAG) -Ilibft -lreadline $(OBJ) -o $(NAME) $(LIBFT)
	@echo "***compilation of $(NAME)***"

clean:
	@rm -rf $(BIN_DIR)
	@echo "***delation of all objects files***"

fclean: clean
	@rm -r $(NAME)
	@echo "***delation of $(NAME)***"

re: fclean all

.PHONY: all clean fclean re libft
