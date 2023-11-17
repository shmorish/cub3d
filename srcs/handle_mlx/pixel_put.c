/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:02:19 by hhino             #+#    #+#             */
/*   Updated: 2023/11/17 00:12:09 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/handle_mlx.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->mlx_utils->addr + (y * data->mlx_utils->line_length + \
			x * (data->mlx_utils->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
