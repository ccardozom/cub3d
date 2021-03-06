/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 12:39:42 by ccardozo          #+#    #+#             */
/*   Updated: 2021/01/27 14:21:17 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"

int		key_press(int keycode, t_game *pos)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		pos->player.walk = +1;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		pos->player.walk = -1;
	if (keycode == KEY_LEFT)
		pos->player.turn = -1;
	else if (keycode == KEY_RIGHT)
		pos->player.turn = +1;
	if (keycode == KEY_A)
		pos->player.l_r = +1;
	else if (keycode == KEY_D)
		pos->player.l_r = -1;
	if (keycode == KEY_ESC)
	{
		exit(0);
	}
	return (0);
}

int		key_release(int keycode, t_game *pos)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		pos->player.walk = 0;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		pos->player.walk = 0;
	else if (keycode == KEY_LEFT)
		pos->player.turn = 0;
	else if (keycode == KEY_RIGHT)
		pos->player.turn = 0;
	else if (keycode == KEY_A)
		pos->player.l_r = 0;
	else if (keycode == KEY_D)
		pos->player.l_r = 0;
	return (0);
}
