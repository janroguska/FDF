# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jroguszk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/26 10:10:30 by jroguszk          #+#    #+#              #
#    Updated: 2018/01/26 10:10:49 by jroguszk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = fdf.c store_map.c draw.c transform.c

OBJ = $(SRC:.c=.o)

LIBFT = includes/libft/libft.a

MINILIBX = minilibx/libmlx.a

HEADER = -c -I fdf.h

all: $(NAME)

$(OBJ): %.o: %.c
		@gcc -c -Wall -Werror -Wextra -I includes/libft/ $< -o $@

$(LIBFT):
	@make -C includes/libft

$(MINILIBX):
	@make -C minilibx

$(NAME): $(LIBFT) $(OBJ) $(MINILIBX)
	@gcc $(OBJ) $(LIBFT) $(MINILIBX) -o $(NAME) -framework OpenGL -framework AppKit

clean:
	/bin/rm -f $(OBJ)
	@make -C includes/libft clean
	@make -C minilibx clean

fclean: clean
	/bin/rm -f $(NAME)
	@make -C includes/libft fclean
	@make -C minilibx clean

re: fclean all
