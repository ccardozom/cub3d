/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 12:39:42 by ccardozo          #+#    #+#             */
/*   Updated: 2020/12/17 09:10:05 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub.h"

int		key_press(int keycode, t_game *pos)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		pos->player.walk = +1;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		pos->player.walk = -1;
	if (keycode == KEY_A || keycode == KEY_LEFT)
		pos->player.turn = -1;
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		pos->player.turn = +1;
	if (keycode == KEY_ESC)
	{
		system("leaks cub3D");
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
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		pos->player.turn = 0;
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		pos->player.turn = 0;
	return (0);
}
