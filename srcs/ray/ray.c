/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 00:32:42 by morishitash       #+#    #+#             */
/*   Updated: 2023/11/10 02:30:32 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ray.h"

double	get_length_ray(t_data *data)
{
	double	point_ray_from_x;
	double	point_ray_from_y;
	double	length_ray;

	point_ray_from_x = get_ray_x(data);
	point_ray_from_y = get_ray_y(data);
	if (point_ray_from_x < point_ray_from_y)
		length_ray = point_ray_from_x;
	else
		length_ray = point_ray_from_y;
	printf("length_ray: %f\n", length_ray);
	return (length_ray);
}
