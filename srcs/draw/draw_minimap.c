/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:02:12 by morishitash       #+#    #+#             */
/*   Updated: 2023/11/23 10:41:12 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/draw.h"

void	draw_square(t_data *data, double x, double y, int color)
{
	int	i;
	int	j;
	int	offset_x;
	int	offset_y;

	i = 0;
	offset_x = x * 5;
	offset_y = y * 5;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			my_mlx_pixel_put(data, offset_x + j, offset_y + i, color);
			// my_mlx_pixel_put(data, x * 5 + j, y * 5 + i, color);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data->mlx_utils->mlx, \
		data->mlx_utils->win, data->mlx_utils->img, 0, 0);
}

void	draw_square_for_map(t_data *data, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			my_mlx_pixel_put(data, x * 5 + j, y * 5 + i, color);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data->mlx_utils->mlx, \
		data->mlx_utils->win, data->mlx_utils->img, 0, 0);
}

void	draw_around(t_data *data, int x, int y, int color)
{
	int	i;
	int	j;

	i = -1;
	while (i < 2)
	{
		j = -1;
		while (j < 2)
		{
			if (x + j < 0 || y + i < 0)
				break;
			my_mlx_pixel_put(data, x + j, y + i, color);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data->mlx_utils->mlx, \
		data->mlx_utils->win, data->mlx_utils->img, 0, 0);
}

void	draw_ray_on_minimap(t_data *data, double x, double y)
{
	int		ray_x;
	int		ray_y;
	int		i;

	// i = 0;
	// while (i < 20)
	// {
	// 	ray_x = x * 5 + cos(data->player_dir) * i;
	// 	ray_y = y * 5 + sin(data->player_dir) * i;
	// 	draw_around(data, ray_x, ray_y, 0x00007F);
	// 	i++;
	// }
	i = 0;
	while (i < 15)
	{
		ray_x = x * 5 + cos(data->player_dir + M_PI_4) * i;
		ray_y = y * 5 + sin(data->player_dir + M_PI_4) * i;
		draw_around(data, ray_x, ray_y, 0x0000FF7F);
		ray_x = x * 5 + cos(data->player_dir - M_PI_4) * i;
		ray_y = y * 5 + sin(data->player_dir - M_PI_4) * i;
		draw_around(data, ray_x, ray_y, 0x0000FF7F);
		i++;
	}
	mlx_put_image_to_window(data->mlx_utils->mlx, \
		data->mlx_utils->win, data->mlx_utils->img, 0, 0);
}

void	draw_minimap(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->parser->map[i] != NULL)
	{
		j = 0;
		while (data->parser->map[i][j] != '\0')
		{
			if (data->parser->map[i][j] == '1')
				draw_square(data, j + 0.5, i + 0.5, 0x0000FF);
			else if (data->parser->map[i][j] == '0'\
				|| is_player(data->parser->map[i][j]) == true)
				draw_square(data, j + 0.5, i + 0.5, 0xFFFFFF);
			j++;
		}
		i++;
	}
	draw_ray_on_minimap(data, data->player_pos_x + 0.5, data->player_pos_y + 0.5);
	draw_square(data, data->player_pos_x, data->player_pos_y, 0xFF0000);
}
