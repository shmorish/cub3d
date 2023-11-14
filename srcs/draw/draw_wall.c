/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:13:17 by morishitash       #+#    #+#             */
/*   Updated: 2023/11/14 00:59:01 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/draw.h"

void	put_file_to_image(t_data *data)
{
	data->texture = (t_texture *)malloc(sizeof(t_texture));
	data->texture->west_wall = mlx_xpm_file_to_image(data->mlx_utils->mlx, \
		"textures/orca_west.xpm", &data->texture->img_width, &data->texture->img_height);
	data->texture->east_wall = mlx_xpm_file_to_image(data->mlx_utils->mlx, \
		"textures/seahorse_east.xpm", &data->texture->img_width, &data->texture->img_height);
	data->texture->west_wall = mlx_xpm_file_to_image(data->mlx_utils->mlx, \
		"textures/penguin_south.xpm", &data->texture->img_width, &data->texture->img_height);
	data->texture->west_wall = mlx_xpm_file_to_image(data->mlx_utils->mlx, \
		"textures/turtle_north.xpm", &data->texture->img_width, &data->texture->img_height);
}

void	wall_image_to_window(t_data *data, int w, int h)
{
	mlx_put_image_to_window(data->mlx_utils->mlx, data->mlx_utils->win, \
		data->texture->west_wall, w * 10, h * 10);
	mlx_put_image_to_window(data->mlx_utils->mlx, data->mlx_utils->win, \
		data->texture->east_wall, w * 10, h * 10);
	mlx_put_image_to_window(data->mlx_utils->mlx, data->mlx_utils->win, \
		data->texture->south_wall, w * 10, h * 10);
	mlx_put_image_to_window(data->mlx_utils->mlx, data->mlx_utils->win, \
		data->texture->north_wall, w * 10, h * 10);
}

void	draw_wall(t_data *data)
{
	int		x;
	int		y;
	int	color;

	x = 0;
	printf("x -> %.02f y ->%.02f\n", data->player_pos_x, data->player_pos_y);
	data->left_ray = data->player_dir + M_PI_4;
	data->right_ray = data->player_dir - M_PI_4;
	while (x <= WINDOW_WIDTH)
	{
		data->length_ray[x] = get_length_ray(data, data->right_ray + (M_PI_2 * x / WINDOW_WIDTH));
		data->visual_height[x] = (int)(WINDOW_HEIGHT / (data->length_ray[x] * 1 / 2));
		x++;
	}
	x = 0;
	y = 0;
	color = 0x00FF00;
	while (x < WINDOW_WIDTH)
	{
		y = 0;
		while (y < WINDOW_HEIGHT)
		{
			if ((WINDOW_HEIGHT - data->visual_height[x]) / 2 <= y \
				&& y <= (WINDOW_HEIGHT + data->visual_height[x]) / 2)
				my_mlx_pixel_put(data, x, y, color);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx_utils->mlx, \
		data->mlx_utils->win, data->mlx_utils->img, 0, 0);
}
