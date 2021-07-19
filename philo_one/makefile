# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/20 02:50:22 by gbabeau           #+#    #+#              #
#    Updated: 2021/07/12 11:54:50 by gbabeau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_one
SRCS = main.c display.c life.c init_philosopher.c  check_argument.c
OBJ = $(SRCS:.c=.o)
CFLAGS = -Wall -Werror -Wextra
CC = gcc  -pthread

G = -g3 -fsanitize=address
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

G: $(OBJ)
	$(CC) $(G) $(OBJ) -o $(NAME)

clean :
	rm -f $(OBJ)
fclean : clean
	rm -f $(NAME)

re: fclean all

.PHONY: bonus  all clean fclean r e

