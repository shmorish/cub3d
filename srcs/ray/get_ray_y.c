/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ray_y.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmorish <shmorish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 01:59:57 by morishitash       #+#    #+#             */
/*   Updated: 2023/11/12 18:47:35 by shmorish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ray.h"

static double	get_ray_y_up(t_data *data, double ray)
{
	double	check_x;
	int		check_y;
	double	length_ray;

	length_ray = __DBL_MAX__;
	check_y = (int)(data->player_pos_y);
	while (1)
	{
		// printf("up ! ");
		if (ray == M_PI_2 || ray == M_PI_2 * 3)
			ray += 0.000001;
		check_x = ((check_y - data->player_pos_y) / tan(ray)) \
					+ data->player_pos_x;
		// printf("check_y %d, data->parser->map_height %d, check_x %d, data->parser->map_width %d\n", (int)check_y, data->parser->map_height, (int)check_x, data->parser->map_width);
		if (check_y < 1 || check_y > data->parser->map_height || check_x < 1 || check_x > data->parser->map_width)
			return (__DBL_MAX__);
		// printf("check[%d][%d] ->  %c",check_y - 1, (int)(check_x), data->parser->map[check_y - 1][(int)(check_x)]);
		if (data->parser->map[check_y - 1][(int)(check_x)] == '1')
		{
			// printf("check_y_up	[%d][%d] ->  %c\n",check_y - 1, (int)(check_x), data->parser->map[check_y - 1][(int)(check_x)]);
			length_ray = sqrt(pow(check_x - data->player_pos_x, 2) \
							+ pow(check_y - data->player_pos_y, 2));
			// printf(" length -> [%f] ", length_ray);
			return (length_ray);
		}
		check_y--;
	}
}

static double	get_ray_y_down(t_data *data, double ray)
{
	double	check_x;
	int		check_y;
	double	length_ray;

	length_ray = __DBL_MAX__;
	check_y = (int)(data->player_pos_y);
	while (1)
	{
		if (ray == M_PI_2 || ray == M_PI_2 * 3)
			ray += 0.000001;
		check_x = (check_y - data->player_pos_y) / tan(ray) \
					+ data->player_pos_x;
		if (check_y < 0 || check_y > data->parser->map_height + 1 || check_x < 0 || check_x > data->parser->map_width + 1)
			return (__DBL_MAX__);
		if (data->parser->map[check_y][(int)(check_x)] == '1')
		{
			// printf("check_y_down	[%d][%d] ->  %c\n",check_y, (int)(check_x), data->parser->map[check_y][(int)(check_x)]);
			length_ray = sqrt(pow(check_x - data->player_pos_x, 2) \
							+ pow(check_y - data->player_pos_y, 2));
			return (length_ray);
		}
		check_y++;
	}
}

double	get_ray_y(t_data *data, double ray)
{
	if (ray < M_PI)
		return (get_ray_y_up(data, ray));
	else
		return (get_ray_y_down(data, ray));
}
