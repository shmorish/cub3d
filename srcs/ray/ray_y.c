/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_y.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:20:05 by morishitash       #+#    #+#             */
/*   Updated: 2023/11/23 22:59:27 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ray.h"

static void	ray_y_init(double *x, int *y, t_data *data, double dir)
{
	if (*y == (int)(data->player_pos_y) && (dir < M_PI))
		*y = *y + 1;
	*x = ((*y - data->player_pos_y) / tan(dir)) + data->player_pos_x;
}

static void	initial_value_y(int *y, t_ray *ray, t_data *data)
{
	*y = (int)(data->player_pos_y);
	ray->ray_length = __DBL_MAX__;
}

static void	get_ray_length_y(t_data *data, double dir, t_ray *ray)
{
	int		y;
	double	x;

	initial_value_y(&y, ray, data);
	while (1)
	{
		ray_y_init(&x, &y, data, dir);
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
	ray->ray_length = ray_length_algorithm(data, dir, x, y);
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
