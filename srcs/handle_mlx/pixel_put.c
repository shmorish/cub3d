/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:02:19 by hhino             #+#    #+#             */
/*   Updated: 2023/12/02 15:28:24 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/handle_mlx.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->mlx_utils->addr + (y * data->mlx_utils->line_length + x
			* (data->mlx_utils->bpp / 8));
	*(unsigned int *)dst = color;
}

uint32_t	get_texel_color(t_wall *wall, int x, int y)
{
	uint32_t	*pix_clr_ptr;

	pix_clr_ptr = (uint32_t *)(wall->addr + y * wall->img_w + x
			* (wall->bpp / 8));
	return (*pix_clr_ptr);
}
