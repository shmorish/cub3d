/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:47:15 by morishitash       #+#    #+#             */
/*   Updated: 2023/10/23 18:19:40 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_data(t_data *data, char *filename)
{
	data->mlx_utils.mlx = mlx_init();
	data->mlx_utils.win = mlx_new_window(data->mlx_utils.mlx, WINDOW_WIDTH, WINDOW_WIDTH, "cub3d");
	data->mlx_utils.img = mlx_new_image(data->mlx_utils.mlx, WINDOW_WIDTH, WINDOW_WIDTH);
	// data->mlx_utils.addr =
}
