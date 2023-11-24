/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:54:04 by morishitash       #+#    #+#             */
/*   Updated: 2023/11/23 22:59:19 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ray.h"

static void	ray_x_init(double *y, int *x, t_data *data, double dir)
{
	if (*x == (int)(data->player_pos_x) && (dir < M_PI_2 || dir > M_PI_2 * 3))
		*x = *x + 1;
	*y = tan(dir) * (*x - data->player_pos_x) + data->player_pos_y;
}

static void	initial_value_x(int *x, t_ray *ray, t_data *data)
{
	*x = (int)(data->player_pos_x);
	ray->ray_length = __DBL_MAX__;
}

static void	get_ray_length_x(t_data *data, double dir, t_ray *ray)
{
	int		x;
	double	y;

	initial_value_x(&x, ray, data);
	while (1)
	{
		ray_x_init(&y, &x, data, dir);
		if (out_map(data, x, y) == true)
			return ;
		if (dir < M_PI_2 || dir > M_PI_2 * 3)
		{
			ray->wall = y - (int)y;
			if (map_is_wall(data, x, (int)y) == true)
				break ;
			x++;
		}
		else
		{
			ray->wall = 1 - (y - (int)y);
			if (map_is_wall(data, x - 1, (int)y) == true)
				break ;
			x--;
		}
	}
	ray->ray_length = ray_length_algorithm(data, dir, x, y);
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
