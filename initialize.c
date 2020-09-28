/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 11:22:02 by ccardozo          #+#    #+#             */
/*   Updated: 2020/09/24 19:09:46 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// void	control_map(t_game *pos)
// {
// 	if (pos->player.player_control != 1)
// 		return_error();
// }
void	initialize(t_game *pos)
{
	read_map(pos);
	create_map(pos);
	// control_map(pos);
	//wall_control(pos.map, pos.rows, pos.columns);
	pos->tile.size = pos->winres.x / pos->columns * pos->player.minimapscale;
	pos->winres.window_width = pos->columns * pos->tile.size  * pos->player.minimapscale;
	pos->winres.window_height = pos->rows * pos->tile.size  * pos->player.minimapscale;
}
