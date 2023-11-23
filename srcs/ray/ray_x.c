/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:54:04 by morishitash       #+#    #+#             */
/*   Updated: 2023/11/23 16:18:33 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ray.h"

static void	get_ray_length_x(t_data *data, double dir, t_ray *ray)
{
	int		x;
	double	y;

	x = (int)(data->player_pos_x);
	ray->ray_length = __DBL_MAX__;
	while (1)
	{
		if ((dir < M_PI_2 || dir > M_PI_2 * 3) && x == (int)(data->player_pos_x))
			x++;
		y = tan(dir) * (x - data->player_pos_x) + data->player_pos_y;
		if (out_map(data, x, y) == true)
			return ;
		if (dir < M_PI_2 || dir > M_PI_2 * 3)
		{
			ray->wall = y - (int)y;
			// if (data->parser->map[(int)y][x] == '1' || data->parser->map[(int)y][x] == ' ')
			// 	break ;
			if (map_is_wall(data, x, (int)y) == true)
				break ;
			x++;
		}
		else
		{
			ray->wall = 1 - (y - (int)y);
			// if (data->parser->map[(int)y][(int)x - 1] == '1' || data->parser->map[(int)y][(int)x - 1] == ' ')
			// 	break ;
			if (map_is_wall(data, x - 1, (int)y) == true)
				break ;
			x--;
		}
	}
	ray->ray_length = sqrt(pow(x - data->player_pos_x, 2) + pow(y - data->player_pos_y, 2)) * cos(dir - data->player_dir);
}

t_ray	*get_length_ray_from_x(t_data *data, double dir)
{
	t_ray	*ray;

	ray = (t_ray *)malloc_err(sizeof(t_ray));
	while (dir < 0)
		dir += 2 * M_PI;
	while (dir > 2 * M_PI)
		dir -= 2 * M_PI;
	get_ray_length_x(data, dir, ray);
	if (dir < M_PI_2 || dir > M_PI_2 * 3)
		ray->dir = EAST;
	else
		ray->dir = WEST;
	return (ray);
}
