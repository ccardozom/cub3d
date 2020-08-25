/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 09:57:34 by ccardozo          #+#    #+#             */
/*   Updated: 2020/08/25 13:02:10 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	update_player(t_game *pos)
{
	float new_player_x;
	float new_player_y;
	
	
	new_player_x = 0;
	new_player_y = 0;
	if (pos->move.left)
		new_player_x = pos->player.x + pos->move.left;
	if (pos->move.rigth)
		new_player_x = pos->player.x + pos->move.rigth;
	if (pos->move.up)	
		new_player_y = pos->player.y + pos->move.up;
	if (pos->move.down)	
		new_player_y = pos->player.y + pos->move.down;
	if (new_player_x)
		pos->player.x = new_player_x;
	if (new_player_y)
		pos->player.y = new_player_y;
}