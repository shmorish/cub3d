/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhino <hhino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:02:19 by hhino             #+#    #+#             */
/*   Updated: 2023/11/22 18:59:23 by hhino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/handle_mlx.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->mlx_utils->addr + (y * data->mlx_utils->line_length + \
			x * (data->mlx_utils->bpp / 8));
	*(unsigned int *)dst = color;
}

void	my_mlx_pixel_put_for_wall(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->texture->east->addr + (y * data->texture->east->line_length + \
			x * (data->texture->east->bpp / 8));
	*(unsigned int *)dst = color;
}
