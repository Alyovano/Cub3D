# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yocapell <yocapell@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/18 12:41:53 by yocapell          #+#    #+#              #
#    Updated: 2020/01/21 09:58:19 by yocapell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_ROOT = ../../

CC = gcc
CCFLAGS = -Wall -Wextra -Werror
INCFLAGS = -I$(LIBFT_ROOT)/srcs/

RM = /bin/rm -f
LIB = ar rcs
MAKE = make

NAME = libftprintf.a

SRC = srcs/ft_convert_chars.c srcs/ft_convert_digit.c srcs/ft_null_manager.c\
srcs/ft_is_printf_specifier.c srcs/ft_manager.c srcs/ft_precision.c \
srcs/ft_precision2.c srcs/ft_precision_utils.c srcs/ft_printf.c \
srcs/ft_width_manager.c srcs/ft_width_manager2.c

OBJ = $(SRC:.c=.o)
INCLUDE = srcs/ft_printf.h

all: libft_all $(NAME)

$(NAME): $(OBJ)
	cp $(LIBFT_ROOT)/libft.a $(NAME)
	$(LIB) $(NAME) $(OBJ)

%.o: %.c $(INCLUDE)
	$(CC) $(CCFLAGS) $(INCFLAGS) -c -o $@ $<

clean: libft_clean
	$(RM) $(OBJ)

fclean: libft_fclean clean
	$(RM) $(NAME)

re: fclean all

libft_all:
	$(MAKE) -C $(LIBFT_ROOT)

libft_clean:
	$(MAKE) -C $(LIBFT_ROOT) clean

libft_fclean:
	$(MAKE) -C $(LIBFT_ROOT) fclean

.PHONY: all clean fclean re
