# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbabeau <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/20 02:50:22 by gbabeau           #+#    #+#              #
#    Updated: 2021/07/07 20:09:22 by gbabeau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_one
SRCS = main.c display.c ft_putnbr_fd.c ft_usleep.c life.c init_philosopher.c ft_atoi.c check_argument.c ft_compare_c_to_s.c
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

