/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:13:17 by morishitash       #+#    #+#             */
/*   Updated: 2023/11/22 18:08:30 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/draw.h"

void	put_file_to_image(t_data *data)
{
	data->texture = (t_texture *)malloc(sizeof(t_texture));
	data->texture->west_wall = mlx_xpm_file_to_image(data->mlx_utils->mlx, \
		data->parser->west_texture, &data->texture->img_w, &data->texture->img_h);
	data->texture->east_wall = mlx_xpm_file_to_image(data->mlx_utils->mlx, \
		data->parser->east_texture, &data->texture->img_w, &data->texture->img_h);
	data->texture->south_wall = mlx_xpm_file_to_image(data->mlx_utils->mlx, \
		data->parser->south_texture, &data->texture->img_w, &data->texture->img_h);
	data->texture->north_wall = mlx_xpm_file_to_image(data->mlx_utils->mlx, \
		data->parser->north_texture, &data->texture->img_w, &data->texture->img_h);
}

void	wall_image_to_window(t_data *data, int w, int h)
{
	put_file_to_image(data);
	mlx_put_image_to_window(data->mlx_utils->mlx, data->mlx_utils->win, \
		data->texture->west_wall, w * 480, h * 480);
	// mlx_put_image_to_window(data->mlx_utils->mlx, data->mlx_utils->win, \
	// 	data->texture->east_wall, w * 480, h * 480);
	// mlx_put_image_to_window(data->mlx_utils->mlx, data->mlx_utils->win, \
	// 	data->texture->south_wall, w * 480, h * 480);
	// mlx_put_image_to_window(data->mlx_utils->mlx, data->mlx_utils->win, \
	// 	data->texture->north_wall, w * 480, h * 480);
}

void	draw_wall(t_data *data)
{
	int		x;
	int		y;
	int	color;

	x = 0;
	// printf("x -> %.02f y ->%.02f\n", data->player_pos_x, data->player_pos_y);
	data->left_ray = data->player_dir + M_PI_4;
	data->right_ray = data->player_dir - M_PI_4;
	while (data->right_ray < 0)
		data->right_ray += 2 * M_PI;
	while (data->right_ray > 2 * M_PI)
		data->right_ray -= 2 * M_PI;
	while (data->left_ray < 0)
		data->left_ray += 2 * M_PI;
	while (data->left_ray > 2 * M_PI)
		data->left_ray -= 2 * M_PI;
	put_ray_data(data);
	while (x <= WINDOW_WIDTH)
	{
		// data->length_ray[x] = get_length_ray(data, data->right_ray + (M_PI_2 * x / WINDOW_WIDTH));
		// printf("data->length_ray[%d] -> %.02f\n", x, data->length_ray[x]);
		// data->visual_height[x] = (int)(WINDOW_HEIGHT / (data->length_ray[x] * 1 / 2));
		data->visual_height[x] = (int)(WINDOW_HEIGHT / (data->length_ray[x] * 2));
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
