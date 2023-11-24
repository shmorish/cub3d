/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 00:33:30 by morishitash       #+#    #+#             */
/*   Updated: 2023/11/23 22:39:04 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "cub3d.h"

typedef struct s_data		t_data;
typedef struct s_ray		t_ray;

void	put_ray_data(t_data	*data);
void	update_ray_data(t_data *data);
bool	out_map(t_data *data, double x, double y);
bool	map_is_wall(t_data *data, int x, int y);
t_ray	*get_length_ray_from_x(t_data *data, double dir);
t_ray	*get_length_ray_from_y(t_data *data, double dir);
double	ray_length_algorithm(t_data *data, double dir, double x, double y);

#endif