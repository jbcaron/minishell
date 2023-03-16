# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcaron <jcaron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 18:26:57 by jcaron            #+#    #+#              #
#    Updated: 2023/03/12 17:06:04 by jcaron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=	src/ft_put_fd.c				\
			src/ft_calloc.c				\
			src/ft_str.c				\
			src/ft_is_num_alpha.c		\
			src/ft_str_is.c				\
			src/get_next_line.c			\
			src/ft_str_research.c		\
			src/ft_bzero.c				\
			src/ft_atoi.c				\
			src/ft_strjoin.c			\
			src/ft_split.c				\
			src/get_closer_pow.c		\
			src/ft_is_special.c			\
			src/dyn_str.c				\
			src/ft_mem.c				\
			src/ft_to_case.c			\
			src/ft_printf/ft_buffer.c	\
			src/ft_printf/put_to.c		\
			src/ft_printf/to_buf_num.c	\
			src/ft_printf/to_buf_word.c	\
			src/ft_printf/to_buf_ptr.c	\
			src/ft_printf/ft_printf.c	\
			src/ft_malloc_1.c			\
			src/ft_malloc_2.c


			
INC		=	./include

NAME	=	libft.a
CC		=	clang
CFLAG	=	-Wall -Wextra -Werror
OBJ 	=	$(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar -crs $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "***creation of library '$(NAME)'***"

%.o: %.c  $(INC)
		@$(CC) $(CFLAG) -I$(INC) -c $< -o $@
		@echo "***compilation of '$<' in '$@'***"


clean:
	@rm -f $(OBJ) $(OBJ_B)
	@echo "***delation of all objects files***"

fclean: clean
	@rm -f $(NAME)
	@echo "***deletion of library '$(NAME)'***"

re: fclean all

so:
	gcc -shared -o libft.so $(OBJ)

.PHONY: all clean fclean re so
