#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pniva <pniva@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/04 13:13:03 by pniva             #+#    #+#              #
#    Updated: 2022/01/11 08:13:05 by pniva            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRCS = srcs/main.c \
		srcs/helper_functions.c \
		srcs/read.c \
		srcs/validate.c \
		srcs/solve.c

NAME = fillit

CC = gcc

CFLAGS = -Wall -Werror -Wextra

INCLUDES = -I ./includes -I ./libft/includes -L ./libft -lft

all: $(NAME)

$(NAME):
		@make -C ./libft/ fclean && make -C ./libft/
		@$(CC) $(FLAGS) $(SRCS) $(INCLUDES) -o $(NAME)

clean:
		@rm -f $(OBJS)

fclean: clean
		@rm -f $(NAME)

re: fclean all
