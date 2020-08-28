/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 12:39:42 by ccardozo          #+#    #+#             */
/*   Updated: 2020/08/28 11:49:10 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		key_press(int keycode, t_game *pos)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		pos->move.walk = +1;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		pos->move.walk = -1;
	if (keycode == KEY_Q || keycode == KEY_LEFT)
		pos->move.turn = -1;
	else if (keycode == KEY_E || keycode == KEY_RIGHT)
		pos->move.turn = +1;
	if (keycode == KEY_ESC)
		exit(0);
	return (0);
}

int		key_release(int keycode, t_game *pos)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		pos->move.walk = 0;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		pos->move.walk = 0;
	else if (keycode == KEY_Q || keycode == KEY_LEFT)
		pos->move.turn = 0;
	else if (keycode == KEY_E || keycode == KEY_RIGHT)
		pos->move.turn = 0;
	return (0);
}
