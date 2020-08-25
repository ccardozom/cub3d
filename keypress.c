/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 12:39:42 by ccardozo          #+#    #+#             */
/*   Updated: 2020/08/25 12:59:05 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		key_press(int keycode, t_game *pos)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		pos->move.up = -3;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		pos->move.down = 3;
	if (keycode == KEY_Q || keycode == KEY_LEFT)
		pos->move.left = -3;
	else if (keycode == KEY_E || keycode == KEY_RIGHT)
		pos->move.rigth = 3;
	return (0);
}

int		key_release(int keycode, t_game *pos)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		pos->move.up = 0;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		pos->move.down = 0;
	else if (keycode == KEY_Q || keycode == KEY_LEFT)
		pos->move.left = 0;
	else if (keycode == KEY_E || keycode == KEY_RIGHT)
		pos->move.rigth = 0;
	// else if (keycode == KEY_ESC)
	// 	return (exit_game(start, EXIT_SUCCESS));
	return (0);
}