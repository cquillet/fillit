# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/24 21:56:02 by cquillet          #+#    #+#              #
#    Updated: 2018/02/06 15:58:59 by cquillet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = simplified_test.c stockshapes.c match_pieces.c algo_x.c matrix.c \
		nodes.c link.c cover.c others.c fillit.c createpattern.c

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc -Wall -Wextra -Werror -o $@ $^

%.o: %.c
	gcc -Wall -Wextra -Werror -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
