/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhino <hhino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:13:17 by morishitash       #+#    #+#             */
/*   Updated: 2023/11/17 19:47:36 by hhino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/draw.h"

void	get_wall_addr(t_data *data)
{
	data->texture->south->addr = \
		mlx_get_data_addr(data->texture->south->wall_img, \
		&data->texture->south->bpp, &data->texture->south->line_length, \
		&data->texture->south->endian);
	data->texture->north->addr = \
		mlx_get_data_addr(data->texture->north->wall_img, \
		&data->texture->north->bpp, &data->texture->north->line_length, \
		&data->texture->north->endian);
	data->texture->west->addr = \
		mlx_get_data_addr(data->texture->west->wall_img, \
		&data->texture->west->bpp, &data->texture->west->line_length, \
		&data->texture->west->endian);
	data->texture->east->addr = \
		mlx_get_data_addr(data->texture->east->wall_img, \
		&data->texture->east->bpp, &data->texture->east->line_length, \
		&data->texture->east->endian);
}

void	put_file_to_image(t_data *data)
{
	data->texture->west->wall_img = mlx_xpm_file_to_image(data->mlx_utils->mlx, \
		data->parser->west_texture, &data->texture->img_w, &data->texture->img_h);
	data->texture->east->wall_img = mlx_xpm_file_to_image(data->mlx_utils->mlx, \
		data->parser->east_texture, &data->texture->img_w, &data->texture->img_h);
	data->texture->south->wall_img = mlx_xpm_file_to_image(data->mlx_utils->mlx, \
		data->parser->south_texture, &data->texture->img_w, &data->texture->img_h);
	data->texture->north->wall_img = mlx_xpm_file_to_image(data->mlx_utils->mlx, \
		data->parser->north_texture, &data->texture->img_w, &data->texture->img_h);
	get_wall_addr(data);
}

void	wall_image_to_window(t_data *data, int w, int h)
{
	put_file_to_image(data);
	mlx_put_image_to_window(data->mlx_utils->mlx, data->mlx_utils->win, \
		data->texture->west->wall_img, w * 480, h * 480);
	mlx_put_image_to_window(data->mlx_utils->mlx, data->mlx_utils->win, \
		data->texture->east->wall_img, w * 480, h * 480);
	mlx_put_image_to_window(data->mlx_utils->mlx, data->mlx_utils->win, \
		data->texture->south->wall_img, w * 480, h * 480);
	mlx_put_image_to_window(data->mlx_utils->mlx, data->mlx_utils->win, \
		data->texture->north->wall_img, w * 480, h * 480);
}

void	draw_wall(t_data *data)
{
	int		x;
	int		y;
	int		color;

	x = 0;
	// printf("x -> %.02f y ->%.02f\n", data->player_pos_x, data->player_pos_y);
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
