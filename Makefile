# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/15 08:55:53 by ccardozo          #+#    #+#              #
#    Updated: 2020/07/20 11:44:23 by ccardozo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3d

SRCS		=	cub3d.c mapa.c check_line.c resolution.c is_map.c\
				get_next_line/get_next_line.c

OBJSRCS		=	${SRCS:.c=.o}

CC 			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

MFLAGS		=	-Lmlx -lmlx -framework OpenGL -framework AppKit

RM			=	rm -rf

# %.o: %.c
# 	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

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
		
fclean:
		$(MAKE) fclean -C ./libft
		$(RM) $(NAME)

re:		fclean $(NAME)

.PHONY:		all clean fclean re