# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: homadani <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/13 11:03:18 by homadani          #+#    #+#              #
#    Updated: 2019/06/17 18:26:01 by homadani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= fillit

INCLUDE= includes/fillit.h

SRC= src/fillit.c\
	 src/free_leak.c\
	 src/shape_handling.c\
	 src/one_line.c \
	 src/cord.c\
	 src/allocate_square.c\
	 src/top_left.c\
	 src/num_of_shapes.c\
	 src/engine_on.c\
	 src/call_error.c\
	 libft/libft.a

all: $(NAME)

$(NAME):
	@cd libft && make re
	@gcc -Wall -Wextra -Werror -o fillit $(SRC) -I $(INCLUDE)

clean:
	@cd libft && make clean
fclean: clean
	@cd libft && make fclean
	@rm -rf $(NAME)

re: fclean all
