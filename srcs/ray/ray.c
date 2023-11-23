/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:16:10 by morishitash       #+#    #+#             */
/*   Updated: 2023/11/23 16:20:21 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ray.h"

bool	out_map(t_data *data, double x, double y)
{
	if (x < 0 || y < 0 || \
		x > data->parser->map_width || y > data->parser->map_height)
	{
		return (true);
	}
	return (false);
}

bool	map_is_wall(t_data *data, int x, int y)
{
	if (data->parser->map[y][x] == '1' || data->parser->map[y][x] == ' ')
		return (true);
	return (false);
}

void	put_ray_data(t_data	*data)
{
	t_ray	*ray_data_x;
	t_ray	*ray_data_y;
	int		x;

	x = 0;
	while (x <= WINDOW_WIDTH)
	{
		ray_data_x = get_length_ray_from_x(data, data->right_ray + (M_PI_2 * x / WINDOW_WIDTH));
		ray_data_y = get_length_ray_from_y(data, data->right_ray + (M_PI_2 * x / WINDOW_WIDTH));
		if (ray_data_x->ray_length < ray_data_y->ray_length)
		{
			data->length_ray[x] = ray_data_x->ray_length;
			data->wall_dir[x] = ray_data_x->dir;
			data->wall_pos[x] = ray_data_x->wall;
		}
		else
		{
			data->length_ray[x] = ray_data_y->ray_length;
			data->wall_dir[x] = ray_data_y->dir;
			data->wall_pos[x] = ray_data_y->wall;
		}
		free(ray_data_x);
		ray_data_x = NULL;
		free(ray_data_y);
		ray_data_y = NULL;
		x++;
	}
}
