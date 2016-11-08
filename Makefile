# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkulish <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/13 16:11:48 by kkulish           #+#    #+#              #
#    Updated: 2016/10/16 16:39:56 by kkulish          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = eval_expr

SRC = main.c ft_putchar.c ft_putstr.c ft_atoi.c operations.c ft_strlen.c \
	  calc.c ft_putnbr.c stack_oper.c stuff.c

OBJ = main.o ft_putchar.o ft_putstr.o ft_atoi.o operations.o ft_strlen.o \
	  calc.o ft_putnbr.o stack_oper.o stuff.o

CFLAGS = -c -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRC) 
	$(CC) $(OBJ) -o$(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
