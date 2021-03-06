# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/09 18:11:48 by rarias-p          #+#    #+#              #
#    Updated: 2021/03/02 16:31:39 by rarias-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=cub3D

CC=gcc

CFLAGS=-Wall -Wextra -Werror -I /usr/local/inlude

BFLAGS=-L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

RM=rm -f

SRC= gnl/get_next_line_bonus.c gnl/get_next_line_utils_bonus.c in_and_out.c archives.c cub3d.c errors.c roto.c file_reader.c map_checker.c keys_manage.c move.c print_errors.c mapper.c textures.c sprites.c utils.c error_numbers.c start_visual.c save_bmp.c engine.c

SANI= -g -fsanitize=address

OBJ= $(SRC:.c=.o);

$(NAME):
		@$(CC) $(CFLAGS) $(SRC) libft.a $(BFLAGS) -o $(NAME);

all:	$(NAME)

clean:
		@$(RM) $(OBJ)
	
fclean: clean
		@$(RM) $(NAME)
		@$(RM) sanitize.out
		@$(RM) debug.out

re: fclean all

valgrind:
		@$(CC) -g $(CFLAGS) $(SRC) libft.a $(BFLAGS) -o debug.out;

sanitize:
		@$(CC) -I /usr/local/inlude $(SRC) libft.a $(BFLAGS) $(SANI) -o sanitize.out;

.PHONY: all clean fclean all

#-Wall -Wextra -Werror -I /usr/local/inlude libft.a gnl/get_next_line_bonus.c gnl/get_next_line_utils_bonus.c archives.c cub3d.c errors.c keys_manage.c print_errors.c in_and_out.c textures.c sprites.c roto.c move.c file_reader.c map_checker.c mapper.c utils.c error_numbers.c start_visual.c save_bmp.c engine.c -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit