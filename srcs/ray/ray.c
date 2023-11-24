/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:16:10 by morishitash       #+#    #+#             */
/*   Updated: 2023/11/23 22:52:59 by morishitash      ###   ########.fr       */
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

double	ray_length_algorithm(t_data *data, double dir, double x, double y)
{
	return (sqrt(pow(x - data->player_pos_x, 2) + \
		pow(y - data->player_pos_y, 2)) \
		* cos(dir - data->player_dir));
}

void	store_data(t_data *data, t_ray *ray, int x)
{
	data->length_ray[x] = ray->ray_length;
	data->wall_dir[x] = ray->dir;
	data->wall_pos[x] = ray->wall;
}

void	put_ray_data(t_data	*data)
{
	t_ray	*ray_data_x;
	t_ray	*ray_data_y;
	int		x;
	double	radian;

	x = 0;
	while (x <= WINDOW_WIDTH)
	{
		radian = data->right_ray + (M_PI_2 * x / WINDOW_WIDTH);
		ray_data_x = get_length_ray_from_x(data, radian);
		ray_data_y = get_length_ray_from_y(data, radian);
		if (ray_data_x->ray_length < ray_data_y->ray_length)
			store_data(data, ray_data_x, x);
		else
			store_data(data, ray_data_y, x);
		free(ray_data_x);
		ray_data_x = NULL;
		free(ray_data_y);
		ray_data_y = NULL;
		x++;
	}
}
