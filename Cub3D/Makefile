# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yocapell <yocapell@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/19 16:16:15 by yocapell          #+#    #+#              #
#    Updated: 2020/02/19 16:56:50 by yocapell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#make -C ./libft/srcs/ft_printf dans all:
#gcc *.o ./libft/srcs/ft_printf/libftprintf.a
CC = gcc

RM = /bin/rm -f

LIB_PATH = ./srcs/libft/srcs/ft_printf/libftprintf.a

RUN = gcc -Wall -Wextra -Werror -lz -o Cub3D ./srcs/window_manager.c \
./srcs/key_press.c ./srcs/sprite.c ./srcs/ft_background_color.c \
./srcs/ft_raycasting.c ./srcs/minimap_drawing.c ./srcs/parser.c \
./srcs/cub3d_free.c ./srcs/utils_to_parse.c ./srcs/extrem_case_parsing.c \
./srcs/token_to_parse.c ./srcs/token_to_parse2.c ./srcs/cub3d.c ./srcs/utils.c \
./srcs/utils2.c ./srcs/utils3.c ./srcs/libft/srcs/ft_printf/libftprintf.a -L \
./srcs/minilibx_opengl -lmlx -framework OpenGL -framework AppKit \

CCFLAGS = -Wall -Wextra -Werror

NAME = cub3d

SRC = ./srcs/key_press.c ./srcs/utils.c ./srcs/cub3d.c ./srcs/cub3d_free.c \
./srcs/minimap_drawing.c ./srcs/utils_to_parse.c ./srcs/extrem_case_parsing.c \
./srcs/parser.c ./srcs/window_manager.c ./srcs/ft_background_color.c \
./srcs/token_to_parse.c ./srcs/ft_raycasting.c ./srcs/token_to_parse2.c \
./srcs/utils2.c ./srcs/utils3.c \

OBJ = $(SRC:.c=.o)

INCLUDE = cub3d.h keycode.h \

%.o: %.c $(INCLUDE)
	$(CC) $(CCFLAGS) -c -o $@ $<


all: $(OBJ)
	@echo "\n"
	@echo "\033[92m=================================================================\033[0m"
	@echo "\033[92m===================Compilation Libftprintf=======================\033[0m"
	@echo "\033[92m=================================================================\033[0m"
	@echo "                                                                                           ";
	@echo "                             bbbbbbbb                                                      ";
	@echo "LLLLLLLLLLL              iiiib::::::b              ffffffffffffffff          tttt          ";
	@echo "L:::::::::L             i::::b::::::b             f::::::::::::::::f      ttt:::t          ";
	@echo "L:::::::::L              iiiib::::::b            f::::::::::::::::::f     t:::::t          ";
	@echo "LL:::::::LL                   b:::::b            f::::::fffffff:::::f     t:::::t          ";
	@echo "  L:::::L              iiiiiiib:::::bbbbbbbbb    f:::::f       fffffttttttt:::::ttttttt    ";
	@echo "  L:::::L              i:::::ib::::::::::::::bb  f:::::f            t:::::::::::::::::t    ";
	@echo "  L:::::L               i::::ib::::::::::::::::bf:::::::ffffff      t:::::::::::::::::t    ";
	@echo "  L:::::L               i::::ib:::::bbbbb:::::::f::::::::::::f      tttttt:::::::tttttt    ";
	@echo "  L:::::L               i::::ib:::::b    b::::::f::::::::::::f            t:::::t          ";
	@echo "  L:::::L               i::::ib:::::b     b:::::f:::::::ffffff            t:::::t          ";
	@echo "  L:::::L               i::::ib:::::b     b:::::bf:::::f                  t:::::t          ";
	@echo "  L:::::L         LLLLLLi::::ib:::::b     b:::::bf:::::f                  t:::::t    tttttt";
	@echo "LL:::::::LLLLLLLLL:::::i::::::b:::::bbbbbb::::::f:::::::f                 t::::::tttt:::::t";
	@echo "L::::::::::::::::::::::i::::::b::::::::::::::::bf:::::::f                 tt::::::::::::::t";
	@echo "L::::::::::::::::::::::i::::::b:::::::::::::::b f:::::::f                   tt:::::::::::tt";
	@echo "LLLLLLLLLLLLLLLLLLLLLLLiiiiiiibbbbbbbbbbbbbbbb  fffffffff                     ttttttttttt  ";
	@echo "                                                                                           ";
	@echo "                                                                                           ";
	@echo "\n"
	make -C ./srcs/libft/srcs/ft_printf
	@echo "\n"
	@echo "\033[92m=================================================================\033[0m"
	@echo "\033[92m======================Compilation Minilibx=======================\033[0m"
	@echo "\033[92m=================================================================\033[0m"
	@echo "\n"
	make -C ./srcs/minilibx_opengl re
	@echo "\n"
	@echo "\033[92m=================================================================\033[0m"
	@echo "\033[92m====================Creation Cub3D executable====================\033[0m"
	@echo "\033[92m=================================================================\033[0m"
	@echo "\n"
	$(RUN)
	@echo "\n"
	@echo "                                    bbbbbbbb                                                  ";
	@echo "        CCCCCCCCCCCCC               b::::::b            333333333333333  DDDDDDDDDDDDD        ";
	@echo "     CCC::::::::::::C               b::::::b           3:::::::::::::::33D::::::::::::DDD     ";
	@echo "   CC:::::::::::::::C               b::::::b           3::::::33333::::::D:::::::::::::::DD   ";
	@echo "  C:::::CCCCCCCC::::C                b:::::b           3333333     3:::::DDD:::::DDDDD:::::D  ";
	@echo " C:::::C       CCCCCuuuuuu    uuuuuu b:::::bbbbbbbbb               3:::::3 D:::::D    D:::::D ";
	@echo "C:::::C             u::::u    u::::u b::::::::::::::bb             3:::::3 D:::::D     D:::::D";
	@echo "C:::::C             u::::u    u::::u b::::::::::::::::b    33333333:::::3  D:::::D     D:::::D";
	@echo "C:::::C             u::::u    u::::u b:::::bbbbb:::::::b   3:::::::::::3   D:::::D     D:::::D";
	@echo "C:::::C             u::::u    u::::u b:::::b    b::::::b   33333333:::::3  D:::::D     D:::::D";
	@echo "C:::::C             u::::u    u::::u b:::::b     b:::::b           3:::::3 D:::::D     D:::::D";
	@echo "C:::::C             u::::u    u::::u b:::::b     b:::::b           3:::::3 D:::::D     D:::::D";
	@echo " C:::::C       CCCCCu:::::uuuu:::::u b:::::b     b:::::b           3:::::3 D:::::D    D:::::D ";
	@echo "  C:::::CCCCCCCC::::u:::::::::::::::ub:::::bbbbbb::::::3333333     3:::::DDD:::::DDDDD:::::D  ";
	@echo "   CC:::::::::::::::Cu:::::::::::::::b::::::::::::::::b3::::::33333::::::D:::::::::::::::DD   ";
	@echo "     CCC::::::::::::C uu::::::::uu:::b:::::::::::::::b 3:::::::::::::::33D::::::::::::DDD     ";
	@echo "        CCCCCCCCCCCCC   uuuuuuuu  uuubbbbbbbbbbbbbbbb   333333333333333  DDDDDDDDDDDDD     By;";
	@echo "                                                                                              ";
	@echo "\n"
	@echo "          ▄▄▄      ██▓  ▓██   ██▓▒█████  ▄████▄  ▄▄▄      ██▓███ ▓█████ ██▓    ██▓    ";
	@echo "         ▒████▄   ▓██▒   ▒██  ██▒██▒  ██▒██▀ ▀█ ▒████▄   ▓██░  ██▓█   ▀▓██▒   ▓██▒    ";
	@echo "         ▒██  ▀█▄ ▒██░    ▒██ ██▒██░  ██▒▓█    ▄▒██  ▀█▄ ▓██░ ██▓▒███  ▒██░   ▒██░    ";
	@echo "         ░██▄▄▄▄██▒██░    ░ ▐██▓▒██   ██▒▓▓▄ ▄██░██▄▄▄▄██▒██▄█▓▒ ▒▓█  ▄▒██░   ▒██░    ";
	@echo "          ▓█   ▓██░██████▒░ ██▒▓░ ████▓▒▒ ▓███▀ ░▓█   ▓██▒██▒ ░  ░▒████░██████░██████▒";
	@echo "          ▒▒   ▓▒█░ ▒░▓  ░ ██▒▒▒░ ▒░▒░▒░░ ░▒ ▒  ░▒▒   ▓▒█▒▓▒░ ░  ░░ ▒░ ░ ▒░▓  ░ ▒░▓  ░";
	@echo "           ▒   ▒▒ ░ ░ ▒  ▓██ ░▒░  ░ ▒ ▒░  ░  ▒    ▒   ▒▒ ░▒ ░     ░ ░  ░ ░ ▒  ░ ░ ▒  ░";
	@echo "           ░   ▒    ░ ░  ▒ ▒ ░░ ░ ░ ░ ▒ ░         ░   ▒  ░░         ░    ░ ░    ░ ░   ";
	@echo "               ░  ░   ░  ░ ░        ░ ░ ░ ░           ░  ░          ░  ░   ░  ░   ░  ░";
	@echo "                         ░ ░            ░                                             ";

clean:
	@echo "\n"
	@echo "\033[92m=================================================================\033[0m"
	@echo "\033[92m====================Suppression des .o===========================\033[0m"
	@echo "\033[92m=================================================================\033[0m"
	@echo "\n"
	make -C ./srcs/libft/srcs/ft_printf clean
	make -C ./srcs/minilibx_opengl clean
	$(RM) ./srcs/*.o

fclean:
	@echo "\n"
	@echo "\033[92m=================================================================\033[0m"
	@echo "\033[92m===========Suppression des .o + lib + executable(s)==============\033[0m"
	@echo "\033[92m=================================================================\033[0m"
	@echo "\n"
	@make -C ./srcs/libft/srcs/ft_printf fclean
	make -C ./srcs/minilibx_opengl clean
	@$(RM) Cub3D
	@$(RM) Cub3D.bmp
	@$(RM) ./srcs/*.o

re: fclean all

norme:
	norminette key_press.c utils.c cub3d.c \
	keycode.h utils2.c cub3d.h minimap_drawing.c \
 	utils_to_parse.c extrem_case_parsing.c parser.c window_manager.c \
 	ft_background_color.c token_to_parse.c ft_raycasting.c token_to_parse2.c \

.PHONY: all clean fclean re
