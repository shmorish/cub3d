/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_y.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:20:05 by morishitash       #+#    #+#             */
/*   Updated: 2023/11/23 16:20:25 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ray.h"

void	get_ray_length_y(t_data *data, double dir, t_ray *ray)
{
	int		y;
	double	x;

	y = (int)(data->player_pos_y);
	ray->ray_length = __DBL_MAX__;
	while (1)
	{
		if (y == (int)(data->player_pos_y) && (dir < M_PI))
			y++;
		x = ((y - data->player_pos_y) / tan(dir)) + data->player_pos_x;
		if (out_map(data, x, y) == true)
			return ;
		if (dir < M_PI)
		{
			ray->wall = x - (int)x;
			if (map_is_wall(data, (int)x, y) == true)
				break ;
			y++;
		}
		else
		{
			ray->wall = 1 - (x - (int)x);
			if (map_is_wall(data, (int)x, y - 1) == true)
				break ;
			y--;
		}
	}
	ray->ray_length = sqrt(pow(x - data->player_pos_x, 2) + pow(y - data->player_pos_y, 2)) * cos(dir - data->player_dir);
}

t_ray	*get_length_ray_from_y(t_data *data, double dir)
{
	t_ray	*ray;

	ray = (t_ray *)malloc_err(sizeof(t_ray));
	while (dir < 0)
		dir += 2 * M_PI;
	while (dir > 2 * M_PI)
		dir -= 2 * M_PI;
	get_ray_length_y(data, dir, ray);
	if (dir < M_PI)
		ray->dir = SOUTH;
	else
		ray->dir = NORTH;
	return (ray);
}