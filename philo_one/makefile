# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/20 02:50:22 by gbabeau           #+#    #+#              #
#    Updated: 2021/07/08 10:20:23 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_one
SRCS = main.c display.c life.c init_philosopher.c  check_argument.c
OBJ = $(SRCS:.c=.o)
CFLAGS = -Wall -Werror -Wextra
CC = gcc -pthread
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)
clean :
	rm -f $(OBJ)
fclean : clean
	rm -f $(NAME)

re: fclean all

.PHONY: bonus  all clean fclean r e

