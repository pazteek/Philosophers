# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/20 02:50:22 by gbabeau           #+#    #+#              #
#    Updated: 2021/06/02 16:23:28 by gbabeau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_two
SRCS = main.c display.c ft_putnbr_fd.c ft_usleep.c life.c init_philosopher.c
OBJ = $(SRCS:.c=.o)
CFLAGS = -Wall -Werror -Wextra
CC = gcc
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)
clean :
	rm -f $(OBJ)
fclean : clean
	rm -f $(NAME)

re: fclean all

.PHONY: bonus  all clean fclean r e

