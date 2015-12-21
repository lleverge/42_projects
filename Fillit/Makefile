# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lleverge <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/21 17:32:58 by lleverge          #+#    #+#              #
#    Updated: 2015/12/21 17:37:59 by lleverge         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC =	fillit.c		ft_check_file.c		ft_lst.c\
		ft_read_file.c	matrix.c			resolve.c

INCLUDES = -I libft/ -I./

LIBS = -L./libft -lft

FLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) -o $(NAME) $(LIBS) $^

%.o: %.c
	gcc $(FLAGS) $(INCLUDES) -c $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
