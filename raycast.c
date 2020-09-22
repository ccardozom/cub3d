/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 11:44:13 by ccardozo          #+#    #+#             */
/*   Updated: 2020/09/22 15:48:08 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"


void	cast_all_rays(t_game *pos)
{
	if(!(pos->rays = (t_rays *)malloc(sizeof(t_rays) * pos->cast.num_rays)))
		return_error(-1);
	pos->ray.rayangle = pos->move.player_angle - (pos->cast.FOV_angle / 2);
}	