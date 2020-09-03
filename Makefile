# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/15 08:55:53 by ccardozo          #+#    #+#              #
#    Updated: 2020/09/03 09:33:20 by ccardozo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3d

SRCS		=	cub3d.c read_map.c check_line.c resolution.c is_map.c \
				open_file.c create_map.c create_matriz.c initialize.c\
				fill_matriz.c return_error.c reset_position.c keypress.c\
				wall_control.c start.c draw_minimap.c draw_player.c\
				initial_position_player.c update_player.c draw_player_move.c\
				raycast.c \
				imprimir_matriz.c \
				get_next_line/get_next_line.c
				#create_window.c draw_map.c 

OBJSRCS		=	${SRCS:.c=.o}

CC 			=	gcc -g

CFLAGS		=	-Wall -Wextra -Werror

MFLAGS		=	-Lmlx -lmlx -framework OpenGL -framework AppKit

#MFLAGS		=	-Lmlx -lmlx -framework OpenGL -framework AppKit

RM			=	rm -rf

$(NAME):	$(OBJSRCS)
		@echo "\033[33m[Removiendo version anterior...]"
		@$(RM) Cub3d
		@echo "\033[33m[Compilando Libft...]"
		@$(MAKE) -C ./libft
		@echo "\033[33m[Compilando Cub3d...]"
		$(CC) $(CFLAGS) ${MFLAGS} $(OBJSRCS) ./libft/libft.a -o $(NAME)

all:	$(NAME)

e:
	./${NAME}

clean:
		${RM} ${OBJSRCS}
		$(MAKE) clean -C ./libft
		$(MAKE) clean -C ./mlx
		
fclean:
		$(MAKE) fclean -C ./libft
		$(MAKE) clean -C ./libft
		$(MAKE) clean -C ./mlx
		$(RM) $(NAME) ${OBJSRCS}
		

re:		fclean $(NAME)

.PHONY:		all clean fclean re