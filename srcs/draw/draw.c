/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhino <hhino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:06:57 by hhino             #+#    #+#             */
/*   Updated: 2023/12/02 19:49:02 by hhino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/draw.h"

void	re_draw(t_data *data)
{
	draw_floor_sky(data);
	draw_wall(data);
	if (data->minimap == true)
		draw_minimap(data);
}

void	draw_floor_sky(t_data *data)
{
	int	color;
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		if (y < WINDOW_HEIGHT / 2)
			color = data->parser->ceiling_color;
		else
			color = data->parser->floor_color;
		while (x < WINDOW_WIDTH)
		{
			my_mlx_pixel_put(data, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_utils->mlx, \
		data->mlx_utils->win, data->mlx_utils->img, 0, 0);
}
