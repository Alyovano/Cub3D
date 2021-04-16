# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yocapell <yocapell@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/18 12:41:53 by yocapell          #+#    #+#              #
#    Updated: 2020/01/22 14:21:41 by alyovano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = srcs/ft_isalpha.c srcs/ft_memccpy.c srcs/ft_memmove.c srcs/ft_strlcpy.c\
srcs/ft_strrchr.c srcs/ft_atoi.c srcs/ft_isascii.c srcs/ft_memchr.c \
srcs/ft_memset.c srcs/ft_strlen.c srcs/ft_nbrlen.c srcs/ft_hexlen.c \
srcs/ft_tolower.c srcs/ft_bzero.c srcs/ft_isdigit.c srcs/ft_memcmp.c \
srcs/ft_strchr.c srcs/ft_strncmp.c srcs/ft_toupper.c srcs/ft_isalnum.c \
srcs/ft_isprint.c srcs/ft_memcpy.c srcs/ft_strlcat.c srcs/ft_strnstr.c \
srcs/ft_calloc.c srcs/ft_strdup.c srcs/ft_substr.c srcs/ft_strjoin.c \
srcs/ft_strtrim.c srcs/ft_split.c srcs/ft_itoa.c srcs/ft_strmapi.c \
srcs/ft_putchar_fd.c srcs/ft_putstr_fd.c srcs/ft_putendl_fd.c \
srcs/ft_isspace.c srcs/ft_putnbr_fd.c srcs/ft_uitoa.c srcs/ft_uitohextoa.c \
srcs/ft_int_init.c srcs/gnl/get_next_line.c srcs/gnl/get_next_line_utils.c \
srcs/ft_strndup.c srcs/ft_swap.c

BSRCS = srcs/ft_lstnew_bonus.c srcs/ft_lstadd_front_bonus.c \
srcs/ft_lstsize_bonus.c srcs/ft_lstlast_bonus.c srcs/ft_lstadd_back_bonus.c \
srcs/ft_lstdelone_bonus.c srcs/ft_lstclear_bonus.c srcs/ft_lstiter_bonus.c \
srcs/ft_lstmap_bonus.c

OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

%.o: %.c
		gcc $(FLAGS) -c $? -o $@

all:	$(NAME) bonus

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

bonus:	$(BOBJS)
		ar rcs $(NAME) $(BOBJS)

clean:
		/bin/rm -f $(OBJS) $(BOBJS)

fclean:		clean
		/bin/rm -f $(NAME)

re:	fclean all

.PHONY: all bonus clean fclean re
