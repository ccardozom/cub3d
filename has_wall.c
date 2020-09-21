/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_wall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 12:23:32 by ccardozo          #+#    #+#             */
/*   Updated: 2020/09/21 20:00:26 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int     wall_colision(t_game *pos, float y, float x)
{
    int col_Y;
    int col_X;

    col_Y = (int)y / pos->tile.size;
    col_X = (int)x / pos->tile.size;
    printf("\ncasilla de colision (%d, %d)\n", col_Y, col_X);
    if (pos->map[col_Y][col_X] == '1')
        return (1);
    return (0);
}
