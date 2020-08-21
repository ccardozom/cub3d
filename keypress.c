/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 12:39:42 by ccardozo          #+#    #+#             */
/*   Updated: 2020/08/21 13:24:57 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		key_press(int keycode, t_game *pos)
{
	if (keycode == KEY_W || keycode == KEY_FORWARD)
		pos->move.down_up.x = -3;
	else if (keycode == KEY_S || keycode == KEY_BACKWARD)
		pos->move.down_up.y = +3;
	if (keycode == KEY_Q || keycode == KEY_LEFT)
		pos->move.left_rigth.x = -3;
	else if (keycode == KEY_E || keycode == KEY_RIGHT)
		pos->move.left_rigth.y = +3;
	return (0);
}

int		key_release(int keycode, t_game *pos)
{
	if (keycode == KEY_W || keycode == KEY_FORWARD)
		pos->move.down_up.x = 0;
	else if (keycode == KEY_S || keycode == KEY_BACKWARD)
		pos->move.down_up.y = 0;
	else if (keycode == KEY_Q || keycode == KEY_LEFT)
		pos->move.left_rigth.x = 0;
	else if (keycode == KEY_E || keycode == KEY_RIGHT)
		pos->move.left_rigth.y = 0;
	// else if (keycode == KEY_ESC)
	// 	return (exit_game(start, EXIT_SUCCESS));
	return (0);
}