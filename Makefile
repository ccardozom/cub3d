# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/15 08:55:53 by ccardozo          #+#    #+#              #
#    Updated: 2020/11/20 11:37:27 by ccardozo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3D

SRCS1		=	cub3d.c read_map.c is_map.c texturas.c\
				open_file.c create_map.c initialize.c\
				return_error.c reset_position.c keypress.c\
				wall_control.c start.c sprites.c\
				position_player.c update_player.c\
				raycast.c has_wall.c raycast_aux.c projection.c projection_aux.c\
				draw/draw_player.c draw/draw_player_move.c draw/draw_minimap.c\
				get_next_line/get_next_line.c

OBJSRCS1		=	${SRCS1:.c=.o}

CC 			=	gcc -g

CFLAGS		=	-Wall -Wextra -Werror

MFLAGS		=	-Lmlx -lmlx -framework OpenGL -framework AppKit

#MFLAGS		=	-Lmlx -lmlx -framework OpenGL -framework AppKit

RM			=	rm -rf

$(NAME):	$(OBJSRCS1)
		@echo "\033[33m[Removiendo version anterior...]"
		@$(RM) Cub3d
		@echo "\033[33m[Compilando Libft...]"
		@$(MAKE) -C ./libft
		@echo "\033[33m[Compilando Cub3d...]"
		$(CC) $(CFLAGS) ${MFLAGS} $(OBJSRCS1) ./libft/libft.a -o $(NAME)

all:	$(NAME)

e:
	./${NAME}

clean:
		${RM} ${OBJSRCS1}
		$(MAKE) clean -C ./libft
		$(MAKE) clean -C ./mlx
		
fclean:
		$(MAKE) fclean -C ./libft
		$(MAKE) clean -C ./libft
		$(MAKE) clean -C ./mlx
		$(RM) $(NAME) ${OBJSRCS1}
		

re:		fclean $(NAME)

.PHONY:		all clean fclean re