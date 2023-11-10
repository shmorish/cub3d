/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ray_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 01:45:11 by morishitash       #+#    #+#             */
/*   Updated: 2023/11/10 13:10:39 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ray.h"

static double	get_ray_x_left(t_data *data, double ray)
{
	int		check_x;
	double	check_y;
	double	length_ray;

	length_ray = __DBL_MAX__;
	check_x = (int)(data->player_pos_x);
	while (1)
	{
		if (ray == M_PI_2 || ray == M_PI_2 * 3)
			ray += 0.000001;
		check_y = tan(ray) * (check_x - data->player_pos_x) \
					+ data->player_pos_y;
		if (check_y < 0 || check_y > data->parser->map_height || check_x < 0 || check_x > data->parser->map_width)
			return (__DBL_MAX__);
		if (data->parser->map[(int)(check_y)][check_x] == '1')
		{
			length_ray = sqrt(pow(check_x - data->player_pos_x, 2) \
							+ pow(check_y - data->player_pos_y, 2));
			return (length_ray);
		}
		check_x--;
	}
}

static double	get_ray_x_right(t_data *data, double ray)
{
	int		check_x;
	double	check_y;
	double	length_ray;

	length_ray = __DBL_MAX__;
	check_x = (int)(data->player_pos_x);
	while (1)
	{
		if (ray == M_PI_2 || ray == M_PI_2 * 3)
			ray += 0.000001;
		check_y = tan(ray) * (check_x - data->player_pos_x) \
					+ data->player_pos_y;
		if (check_y < 0 || check_y > data->parser->map_height || check_x < 0 || check_x > data->parser->map_width)
			return (__DBL_MAX__);
		if (data->parser->map[(int)(check_y)][check_x] == '1')
		{
			printf("check_x: %d check_y: %d\n", check_x, (int)(check_y - 0.5));
			length_ray = sqrt(pow(check_x - data->player_pos_x, 2) \
							+ pow(check_y - data->player_pos_y, 2));
			return (length_ray);
		}
		check_x++;
	}
}

double	get_ray_x(t_data *data, double ray)
{
	if (M_PI_2 < data->player_dir && data->player_dir < M_PI_2 * 3)
		return (get_ray_x_left(data, ray));
	else
		return (get_ray_x_right(data, ray));
}
