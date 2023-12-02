/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhino <hhino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:13:17 by morishitash       #+#    #+#             */
/*   Updated: 2023/12/02 19:48:45 by hhino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/draw.h"

typedef struct s_count
{
	int	i;
	int	j;
	int	k;
	int	l;

	int	y;
}	t_count;

void	calculate_visual_height(t_data *data)
{
	int	x;

	x = 0;
	update_ray_data(data);
	put_ray_data(data);
	while (x <= WINDOW_WIDTH)
	{
		data->visual_height[x] = \
			(int)((WINDOW_HEIGHT / (data->length_ray[x] * 8 / 7)));
		x++;
	}
}

static int	get_texture_color(t_data *data, int x, t_count *count)
{
	int	color;

	color = 0x00FF00;
	if (data->wall_dir[x] == SOUTH)
	{
		color = calculate_wall_coordinates(data->texture->south, \
			data->wall_pos[x], data->visual_height[x], (*count).i++);
	}
	else if (data->wall_dir[x] == NORTH)
	{
		color = calculate_wall_coordinates(data->texture->north, \
			data->wall_pos[x], data->visual_height[x], (*count).j++);
	}
	else if (data->wall_dir[x] == WEST)
	{
		color = calculate_wall_coordinates(data->texture->west, \
			data->wall_pos[x], data->visual_height[x], (*count).k++);
	}
	else if (data->wall_dir[x] == EAST)
	{
		color = calculate_wall_coordinates(data->texture->east, \
			data->wall_pos[x], data->visual_height[x], (*count).l++);
	}
	return (color);
}

void	count_init(t_count *count)
{
	(*count).i = 0;
	(*count).j = 0;
	(*count).k = 0;
	(*count).l = 0;
	(*count).y = 0;
}

void	draw_wall(t_data *data)
{
	int		x;
	int		color;
	t_count	count;

	calculate_visual_height(data);
	x = 0;
	color = 0x00FF00;
	while (x < WINDOW_WIDTH)
	{
		count_init(&count);
		while (count.y < WINDOW_HEIGHT)
		{
			if ((WINDOW_HEIGHT - data->visual_height[x]) / 2 <= count.y \
				&& count.y <= (WINDOW_HEIGHT + data->visual_height[x]) / 2)
			{
				color = get_texture_color(data, x, &count);
				my_mlx_pixel_put(data, x, count.y, color);
			}
			count.y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx_utils->mlx, \
		data->mlx_utils->win, data->mlx_utils->img, 0, 0);
}
