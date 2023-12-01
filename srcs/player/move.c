/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:45:19 by hhino             #+#    #+#             */
/*   Updated: 2023/12/01 21:50:08 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/player.h"

static void	movement(int keycode, t_data *data)
{
	double	sin_dir;
	double	cos_dir;

	sin_dir = sin(data->player_dir) * MOVE_SPEED;
	cos_dir = cos(data->player_dir) * MOVE_SPEED;
	if (keycode == KEY_W)
		wall_judge(data, cos_dir, sin_dir);
	else if (keycode == KEY_S)
		wall_judge(data, -cos_dir, -sin_dir);
	else if (keycode == KEY_D)
		wall_judge(data, -sin_dir, cos_dir);
	else if (keycode == KEY_A)
		wall_judge(data, sin_dir, -cos_dir);
	else if (keycode == KEY_Q)
		data->minimap = !(data->minimap);
	else if (keycode == KEY_P)
		data->fish_eye = !(data->fish_eye);
	else if (keycode == KEY_RIGHT_ARROW)
		data->player_dir += M_PI_4 / 2;
	else if (keycode == KEY_LEFT_ARROW)
		data->player_dir -= M_PI_4 / 2;
	re_draw(data);
}

int	move_player(int keycode, t_data *data)
{
	if (keycode == KEY_UP_ARROW || keycode == KEY_DOWN_ARROW || \
		keycode == KEY_RIGHT_ARROW || keycode == KEY_LEFT_ARROW || \
		keycode == KEY_D || keycode == KEY_A || keycode == KEY_S || \
		keycode == KEY_W || keycode == KEY_Q || keycode == KEY_P)
		movement(keycode, data);
	else if (keycode == KEY_ESC)
		close_window_esc(keycode, data);
	return (0);
}

int	mouse_move(int x, int y, t_data *data)
{
	(void)y;
	if (x < WINDOW_WIDTH / 2)
		data->player_dir -= 0.1;
	else if (x > WINDOW_WIDTH / 2)
		data->player_dir += 0.1;
	re_draw(data);
	return (0);
}

void	game_in_progress(t_data *data)
{
	mlx_hook(data->mlx_utils->win, KEY_PRESS, 1L << 0, move_player, data);
	mlx_hook(data->mlx_utils->win, 17, 0L, close_window_botton, data);
	// mlx_hook(data->mlx_utils->win, 6, 1L << 6, mouse_move, data);
	mlx_loop(data->mlx_utils->mlx);
	// mlx_mouse_show();
}
