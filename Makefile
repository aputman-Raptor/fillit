#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yboualla <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/26 15:11:11 by yboualla          #+#    #+#              #
#    Updated: 2016/04/21 18:11:11 by aputman          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =	fillit

SRC =	fillit.c \
		save_tetr.c \
		checks.c \
		readfile.c \
		lsttetr.c \
		map.c \
		err.c

OBJ =	$(SRC:.c=.o)

LIB =	libft/libft.a

FLG =	-Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	make -C libft
	gcc -c $(FLG) $(SRC)
	gcc -o $(NAME) $(OBJ) $(LIB)

clean:
	make clean -C libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
