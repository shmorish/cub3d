/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhino <hhino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:13:17 by morishitash       #+#    #+#             */
/*   Updated: 2023/11/29 19:09:05 by hhino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/draw.h"

// void	wall_image_to_window(t_data *data, int w, int h)
// {
// 	put_file_to_image(data);
// 	mlx_put_image_to_window(data->mlx_utils->mlx, data->mlx_utils->win,
// 		data->texture->west->wall_img, w * 0, h * 0);
// 	mlx_put_image_to_window(data->mlx_utils->mlx, data->mlx_utils->win, \
// 		data->texture->east->wall_img, w * 480, h * 480);
// 	mlx_put_image_to_window(data->mlx_utils->mlx, data->mlx_utils->win, \
// 		data->texture->south->wall_img, w * 480, h * 480);
// 	mlx_put_image_to_window(data->mlx_utils->mlx, data->mlx_utils->win, \
// 		data->texture->north->wall_img, w * 480, h * 480);
// }

// void	draw_wall(t_data *data)
// {
// 	int	x;
// 	int	y;
// 	int	color;

// 	x = 0;
// 	update_ray_data(data);
// 	put_ray_data(data);
// 	while (x <= WINDOW_WIDTH)
// 	{
// 		data->visual_height[x] = (int)((WINDOW_HEIGHT / (data->length_ray[x] * 8
// 					/ 7)));
// 		x++;
// 	}
// 	x = 0;
// 	y = 0;
// 	color = 0x00FF00;
// 	while (x < WINDOW_WIDTH)
// 	{
// 		y = 0;
// 		while (y < WINDOW_HEIGHT)
// 		{
// 			if ((WINDOW_HEIGHT - data->visual_height[x]) / 2 <= y
// 				&& y <= (WINDOW_HEIGHT + data->visual_height[x]) / 2)
// 			{
// 				printf("out! -> x = %f\n", data->wall_pos[x]);
// 				// if (data->wall_dir[x] == SOUTH)
// 				// 	color = calculate_wall_coordinates(data, data->texture->south, data->wall_pos[x]);
// 				// else if (data->wall_dir[x] == NORTH)
// 				// 	color = calculate_wall_coordinates(data, data->texture->north, data->wall_pos[x]);
// 				// else if (data->wall_dir[x] == WEST)
// 				// 	color = calculate_wall_coordinates(data, data->texture->west, data->wall_pos[x]);
// 				// else if (data->wall_dir[x] == EAST)
// 				// 	color = calculate_wall_coordinates(data, data->texture->east, data->wall_pos[x]);
// 				if (data->wall_pos[x] < 0.02)
// 					color = 0x000000;
// 				my_mlx_pixel_put(data, x, y, color);
// 			}
// 			y++;
// 		}
// 		x++;
// 	}
// 	mlx_put_image_to_window(data->mlx_utils->mlx, data->mlx_utils->win,
// 		data->mlx_utils->img, 0, 0);
// }

void	draw_wall(t_data *data)
{
	int		x;
	int		y;
	int		color;

	x = 0;
	update_ray_data(data);
	put_ray_data(data);
	put_file_to_image(data);
	while (x <= WINDOW_WIDTH)
	{
		data->visual_height[x] = (int)((WINDOW_HEIGHT / (data->length_ray[x] * 8
					/ 7)));
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
			// printf("out! -> x = %f\n", data->wall_pos[x]);
			if ((WINDOW_HEIGHT - data->visual_height[x]) / 2 <= y \
				&& y <= (WINDOW_HEIGHT + data->visual_height[x]) / 2)
			{
				if (data->wall_dir[x] == SOUTH)
					color = calculate_wall_coordinates(data, data->texture->south, data->wall_pos[x]);
				else if (data->wall_dir[x] == NORTH)
					color = calculate_wall_coordinates(data, data->texture->north, data->wall_pos[x]);
				else if (data->wall_dir[x] == WEST)
					color = calculate_wall_coordinates(data, data->texture->west, data->wall_pos[x]);
				else if (data->wall_dir[x] == EAST)
					color = calculate_wall_coordinates(data, data->texture->east, data->wall_pos[x]);
				if (data->wall_pos[x] < 0.02)
					color = 0x000000;
				my_mlx_pixel_put(data, x, y, color);
			}
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx_utils->mlx, \
		data->mlx_utils->win, data->mlx_utils->img, 0, 0);
}
