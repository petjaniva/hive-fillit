#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pniva <pniva@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/04 13:13:03 by pniva             #+#    #+#              #
#    Updated: 2022/01/04 14:02:46 by pniva            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRCS =

NAME = fillit

CC = gcc

CFLAGS = -Wall -Werror -Wextra

INCLUDES = -I ./includes -I ./libft/includes -L ./libft -lft

all: libft $(NAME)

$(NAME):
		$(CC) $(FLAGS) $(SRCS) $(INCLUDES) -o $(NAME)

libft:
		@make -C ../libft/ fclean && make -C ../libft/

clean:
		@rm -f $(OBJS)

fclean: clean
		@rm -f $(NAME)

re: fclean all
