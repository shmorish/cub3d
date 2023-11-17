/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:48:05 by morishitash       #+#    #+#             */
/*   Updated: 2023/11/10 10:35:46 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_data(t_data *data)
{
	free(data->mlx_utils);
	data->mlx_utils = NULL;
	free(data->length_ray);
	data->length_ray = NULL;
	free(data->visual_height);
	data->visual_height = NULL;
	free(data);
	data = NULL;
}
