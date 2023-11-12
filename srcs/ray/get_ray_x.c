/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ray_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmorish <shmorish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 01:45:11 by morishitash       #+#    #+#             */
/*   Updated: 2023/11/12 22:12:05 by shmorish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ray.h"

int i = 0;

static double	get_ray_x_left(t_data *data, double ray)
{
	int		check_x;
	double	check_y;
	double	length_ray;

	length_ray = __DBL_MAX__;
	check_x = (int)(data->player_pos_x);
	// if (i < 200)
	// 	printf("--------------\n");
	while (1)
	{
		if (ray == M_PI_2 || ray == M_PI_2 * 3)
			ray += 0.000001;
		check_y = tan(ray) * (check_x - data->player_pos_x) \
					+ data->player_pos_y;
		// if (i++ < 200)
		// 	printf("check_y %d, data->parser->map_height %d, check_x %d, data->parser->map_width %d data->parser->map[%d][%d]\n", (int)check_y, data->parser->map_height, check_x, data->parser->map_width, (int)(check_y - 1), check_x);
		if (check_y < 0 || (int)check_y > data->parser->map_height || check_x < 0 || check_x > data->parser->map_width - 1)
			return (__DBL_MAX__);
		// printf("ray %d° check_y %d, map_height %d, check_x %d, map_width %d map[%d][%d]\n", \
		// 	(int)(ray * 180 * M_1_PI), (int)check_y, data->parser->map_height, check_x, data->parser->map_width, (int)(check_y), check_x);
		if (data->parser->map[(int)(check_y)][check_x - 1] == '1')
		{
			// if (i < 200)
			// 	printf("check_x_left	[%d][%d] ->  %c\n", (int)check_y - 1, (int)(check_x), data->parser->map[(int)check_y - 1][(int)(check_x)]);
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
	check_x = (int)(data->player_pos_x) + 1;
	while (1)
	{
		if (ray == M_PI_2 || ray == M_PI_2 * 3)
			ray += 0.000001;
		check_y = tan(ray) * (check_x - data->player_pos_x) \
					+ data->player_pos_y;
		if (check_y < 1 || check_y > data->parser->map_height || check_x < 0 || check_x > data->parser->map_width)
			return (__DBL_MAX__);
		// if (ray == 7 * M_PI_4)
		// {
		// 	printf("ray %d° check_y %d, map_height %d, check_x %d, map_width %d map[%d][%d]\n", \
		// 		(int)(ray * 180 * M_1_PI), (int)check_y, data->parser->map_height, check_x, data->parser->map_width, (int)(check_y), check_x);
		// }
		if (data->parser->map[(int)(check_y)][check_x + 1] == '1')
		{
			// printf("check_x_right	[%d][%d] ->  %c\n", (int)check_y, (int)(check_x), data->parser->map[(int)check_y][(int)(check_x)]);
			length_ray = sqrt(pow(check_x - data->player_pos_x, 2) \
							+ pow(check_y - data->player_pos_y, 2));
			return (length_ray);
		}
		check_x++;
	}
}

// 左右の壁判定
double	get_ray_x(t_data *data, double ray)
{
	// printf("%f -> %d tan(ray)[%.03f] ", ray, (int)(ray * 180 * M_1_PI), tan(ray));
	if (M_PI_2 < ray && ray < M_PI_2 * 3)
		return (get_ray_x_left(data, ray));
	else
		return (get_ray_x_right(data, ray));
}
