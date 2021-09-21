# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbonini <fbonini@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/01 15:33:15 by fbonini           #+#    #+#              #
#    Updated: 2021/07/08 11:59:22 by fbonini          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
CC			= gcc
RM			= rm -f
FLAGS		= -Wall -Wextra -Werror
LIBS		= ft_printf.h
INCLUDES	=./
OBJ			= ft_printf.o ft_struct.o \
		ft_get_char.o ft_get_hex.o \
		ft_get_integer.o ft_get_pointer.o \
		ft_get_string.o ft_get_uint.o \
		ft_printf_con.o ft_printf_fills.o \
		ft_flag_checks.o ft_flags.o \
		ft_printf_utils.o ft_checks_hex.o \
		ft_checks_int.o

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

%.o: %.c $(LIBS)
	$(CC) $(FLAGS) -I$(INCLUDES) $< -c -o $@

clean:
	$(RM) $(OBJ) $(BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re