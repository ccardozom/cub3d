/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 11:44:13 by ccardozo          #+#    #+#             */
/*   Updated: 2020/09/22 00:21:09 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"


void	cast_all_rays(t_game *pos)
{
	if(!(pos->rays = (t_ray_col *)malloc(sizeof(pos->cast.num_rays) * t_ray_col + 1)))
		return_error();
	pos->ray.rayangle = pos->move.player_angle - (pos->cast.FOV_angle / 2);
}	