# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/15 08:55:53 by ccardozo          #+#    #+#              #
#    Updated: 2021/01/25 15:40:48 by ccardozo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3D

NAMEBONUS	=	cub3D_bonus

SRCS1		=	cub3d.c read_map.c is_map.c texturas.c utils.c\
				open_file.c create_map.c initialize.c save.c\
				return_error.c reset_position.c keypress.c\
				wall_control.c start.c sprites.c sprites_aux.c checker.c\
				position_player.c update_player.c\
				raycast.c has_wall.c raycast_aux.c projection.c projection_aux.c\
				draw/draw_player.c draw/draw_minimap.c\
				get_next_line/get_next_line.c

SRCBONUS	=	bonus/draw_player_move_bonus.c bonus/draw_minimap_bonus.c\
				cub3d.c read_map.c is_map.c texturas.c utils.c\
				open_file.c create_map.c initialize.c save.c\
				return_error.c reset_position.c keypress.c\
				wall_control.c start.c sprites.c sprites_aux.c checker.c\
				position_player.c update_player_bonus.c\
				raycast.c has_wall.c raycast_aux.c projection.c projection_aux.c\
				draw/draw_player.c\
				get_next_line/get_next_line.c

INCLUDE		=	include/cub.h

INCLUDEBONUS =	include/cub_bonus.h

MAPA		=	map.cub

OBJSRCS1		=	${SRCS1:.c=.o}

OBJSSRCBONUS	=	${SRCBONUS:.c=.o}

CC			=	gcc -g

NORM	=	norminette

CFLAGS		=	-Wall -Wextra -Werror

MFLAGS		=	-Lmlx -lmlx -framework OpenGL -framework AppKit

RM			=	rm -rf

$(NAME):	$(OBJSRCS1)
		@echo "\033[33m[Removiendo version anterior...]"
		@$(RM) Cub3d
		@echo "\033[33m[Compilando Libft...]"
		@$(MAKE) -C ./libft
		@echo "\033[33m[Compilando Cub3d...]"
		$(CC) $(CFLAGS) ${MFLAGS} $(OBJSRCS1) ./libft/libft.a -o $(NAME)

$(NAMEBONUS):	$(OBJSSRCBONUS)
		@echo "\033[33m[Removiendo version anterior...]"
		@$(RM) Cub3d
		@echo "\033[33m[Compilando Libft...]"
		@$(MAKE) -C ./libft
		@echo "\033[33m[Compilando Cub3d...]"
		$(CC) $(CFLAGS) ${MFLAGS} $(OBJSSRCBONUS) ./libft/libft.a -o $(NAMEBONUS)

bonus:	$(NAMEBONUS)

norma:
	@$(NORM) $(SRCS1) $(INCLUDE)

normabonus:
	@$(NORM) $(SRCBONUS) $(INCLUDEBONUS)

all:	$(NAME)

run:
	@./${NAME} $(MAPA)

runbonus:
	@./${NAMEBONUS} $(MAPA)

clean:
		${RM} ${OBJSRCS1} ${OBJSSRCBONUS}
		$(MAKE) clean -C ./libft
		$(MAKE) clean -C ./mlx
		
fclean: clean
		$(MAKE) fclean -C ./libft
		$(RM) $(NAME) $(NAMEBONUS)
		

re:		fclean $(NAME)

.PHONY:		all clean fclean re