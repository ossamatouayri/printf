# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ostouayr <ostouayr@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/12 11:12:16 by ostouayr          #+#    #+#              #
#    Updated: 2024/11/12 15:28:45 by ostouayr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FILES_C = ft_printf.c ft_putchar.c ft_putstr.c ft_print_adress.c ft_putnbr.c ft_print_unsigned.c ft_print_hexa.c 

OBJF = $(SRC_FILES_C:.c=.o)

NAME = libftprintf.a

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

CC = cc

all: $(NAME)

clean:
		$(RM) $(OBJF)

$(NAME): $(OBJF)
		ar rcs $(NAME) $(OBJF)

%.o:%.c ft_printf.h
		$(CC) $(CFLAGS) -c $< -o $@

fclean: clean
		$(RM) $(NAME)

re: fclean all
