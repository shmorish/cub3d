/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 00:32:42 by morishitash       #+#    #+#             */
/*   Updated: 2023/11/22 17:02:06 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ray.h"

double	get_length_ray(t_data *data, double ray)
{
	double	length_ray;

	while (ray < 0)
		ray += 2 * M_PI;
	while (ray > 2 * M_PI)
		ray -= 2 * M_PI;
	length_ray = __DBL_MAX__;
	(void)data;
	// data->ray->point_ray_x = get_ray_x(data, ray);
	// data->ray->point_ray_y = get_ray_y(data, ray);
	// if (data->ray->point_ray_x < data->ray->point_ray_y)
	// {
	// 	// 魚眼レンズ
	// 	// length_ray = point_ray_from_x;
	// 	// 魚眼レンズは直したけど、ある方向を向いたらSEGVが出る
	// 	length_ray = data->ray->point_ray_x * cos(ray - data->player_dir);
	// }
	// else
	// {
	// 	// 上記同様。
	// 	// length_ray = point_ray_from_y;
	// 	length_ray = data->ray->point_ray_y * cos(ray - data->player_dir);
	// }
	return (length_ray);
}
