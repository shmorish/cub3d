/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 00:33:30 by morishitash       #+#    #+#             */
/*   Updated: 2023/11/22 17:01:08 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "cub3d.h"

typedef struct s_data		t_data;

double	get_length_ray(t_data *data, double ray);
double	get_ray_x(t_data *data, double ray);
double	get_ray_y(t_data *data, double ray);

void	put_ray_data(t_data	*data);

#endif