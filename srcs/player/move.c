/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:45:19 by hhino             #+#    #+#             */
/*   Updated: 2023/11/13 10:46:48 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/player.h"

void	re_draw(t_data *data)
{
	mlx_destroy_image(data->mlx_utils->mlx, data->mlx_utils->img);
	data->mlx_utils->img = \
		mlx_new_image(data->mlx_utils->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	data->mlx_utils->addr = mlx_get_data_addr(data->mlx_utils->img, \
		&data->mlx_utils->bits_per_pixel, &data->mlx_utils->line_length, \
		&data->mlx_utils->endian);
	draw_floor_sky(data);
	draw_wall(data);
}

static void	movement(int keycode, t_data *data)
{
	if (keycode == KEY_UP_ARROW)
	{
		data->player_pos_x += cos(data->player_dir) * MOVE_SPEED;
		data->player_pos_y += sin(data->player_dir) * MOVE_SPEED;
	}
	else if (keycode == KEY_DOWN_ARROW)
	{
		data->player_pos_x -= cos(data->player_dir) * MOVE_SPEED;
		data->player_pos_y -= sin(data->player_dir) * MOVE_SPEED;
	}
	else if (keycode == KEY_RIGHT_ARROW)
	{
		data->player_pos_x -= sin(data->player_dir) * MOVE_SPEED;
		data->player_pos_y += cos(data->player_dir) * MOVE_SPEED;
	}
	else if (keycode == KEY_LEFT_ARROW)
	{
		data->player_pos_x += sin(data->player_dir) * MOVE_SPEED;
		data->player_pos_y -= cos(data->player_dir) * MOVE_SPEED;
	}
	else if (keycode == KEY_D)
		data->player_dir += 0.2;
	else if (keycode == KEY_A)
		data->player_dir -= 0.2;
	re_draw(data);
}

int	move_player(int keycode, t_data *data)
{
	printf("MOVE\n");
	if (keycode == KEY_UP_ARROW || keycode == KEY_DOWN_ARROW || \
		keycode == KEY_RIGHT_ARROW || keycode == KEY_LEFT_ARROW || \
		keycode == KEY_D || keycode == KEY_A)
		movement(keycode, data);
	else if (keycode == KEY_ESC)
		close_window_esc(keycode, data);
	return (0);
}

void	game_in_progress(t_data *data)
{
	mlx_hook(data->mlx_utils->win, KEY_PRESS, 1L << 0, move_player, data);
	mlx_hook(data->mlx_utils->win, 17, 0L, close_window_botton, data);
	mlx_loop(data->mlx_utils->mlx);
	mlx_mouse_show();
}
