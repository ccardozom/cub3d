/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 11:44:13 by ccardozo          #+#    #+#             */
/*   Updated: 2020/09/03 12:45:09 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// int		castray(t_game *pos)
// {
	
// }
void	cast_all_rays(t_game *pos)
{
	pos->cast.num_rays = pos->winres.x;
	pos->ray.rayAngle = pos->cast.fov_angle / pos->cast.num_rays;
	printf("%f ", pos->ray.rayAngle);
}