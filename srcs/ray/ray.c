/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 00:32:42 by morishitash       #+#    #+#             */
/*   Updated: 2023/11/10 13:03:23 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ray.h"

double	get_length_ray(t_data *data, double ray)
{
	double	point_ray_from_x;
	double	point_ray_from_y;
	double	length_ray;

	while (ray < 0)
		ray += 2 * M_PI;
	while (ray > 2 * M_PI)
		ray -= 2 * M_PI;
	point_ray_from_x = get_ray_x(data, ray);
	point_ray_from_y = get_ray_y(data, ray);
	if (point_ray_from_x < point_ray_from_y)
	{
		// printf("point_ray_from_x: %f\n", point_ray_from_x);
		length_ray = point_ray_from_x;
	}
	else
	{
		// printf("point_ray_from_y: %f\n", point_ray_from_y);
		length_ray = point_ray_from_y;
	}
	return (length_ray);
}
