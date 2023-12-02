/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhino <hhino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:13:17 by morishitash       #+#    #+#             */
/*   Updated: 2023/12/02 15:16:29 by hhino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/draw.h"

void	draw_wall(t_data *data)
{
	int		x;
	int		y;
	int		i;
	int		j;
	int		k;
	int		l;
	int		color;

	x = 0;
	update_ray_data(data);
	put_ray_data(data);
	put_file_to_image(data);
	while (x <= WINDOW_WIDTH)
	{
		data->visual_height[x] = \
			(int)((WINDOW_HEIGHT / (data->length_ray[x] * 8 / 7)));
		x++;
	}
	x = 0;
	y = 0;
	i = 0;
	j = 0;
	k = 0;
	l = 0;
	color = 0x00FF00;
	while (x < WINDOW_WIDTH)
	{
		y = 0;
		i = 0;
		j = 0;
		k = 0;
		l = 0;
		while (y < WINDOW_HEIGHT)
		{
			if ((WINDOW_HEIGHT - data->visual_height[x]) / 2 <= y \
				&& y <= (WINDOW_HEIGHT + data->visual_height[x]) / 2)
			{
				if (data->wall_dir[x] == SOUTH)
				{
					color = calculate_wall_coordinates(data->texture->south, data->wall_pos[x], data->visual_height[x], i);
					i++;
				}
				else if (data->wall_dir[x] == NORTH)
				{
					color = calculate_wall_coordinates(data->texture->north, data->wall_pos[x], data->visual_height[x], j);
					j++;
				}
				else if (data->wall_dir[x] == WEST)
				{
					color = calculate_wall_coordinates(data->texture->west, data->wall_pos[x], data->visual_height[x], k);
					k++;
				}
				else if (data->wall_dir[x] == EAST)
				{
					color = calculate_wall_coordinates(data->texture->east, data->wall_pos[x], data->visual_height[x], l);
					l++;
				}
				my_mlx_pixel_put(data, x, y, color);
			}
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx_utils->mlx, \
		data->mlx_utils->win, data->mlx_utils->img, 0, 0);
}
