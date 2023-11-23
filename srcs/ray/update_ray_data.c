/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_ray_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:22:09 by morishitash       #+#    #+#             */
/*   Updated: 2023/11/23 22:18:14 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ray.h"

void	update_ray_data(t_data *data)
{
	data->left_ray = data->player_dir + M_PI_4;
	data->right_ray = data->player_dir - M_PI_4;
	while (data->right_ray < 0)
		data->right_ray += 2 * M_PI;
	while (data->right_ray > 2 * M_PI)
		data->right_ray -= 2 * M_PI;
	while (data->left_ray < 0)
		data->left_ray += 2 * M_PI;
	while (data->left_ray > 2 * M_PI)
		data->left_ray -= 2 * M_PI;
}
