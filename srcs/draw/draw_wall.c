/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmorish <shmorish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:13:17 by morishitash       #+#    #+#             */
/*   Updated: 2023/11/12 20:15:15 by shmorish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/draw.h"

void	draw_wall(t_data *data)
{
	int		x;
	int		y;

	x = 0;
	while (x <= WINDOW_WIDTH)
	{
		data->length_ray[x] = get_length_ray(data, data->right_ray + (M_PI_2 * x / WINDOW_WIDTH));
		data->visual_height[x] = (int)(WINDOW_HEIGHT / (data->length_ray[x] * 1 / 4));

		// printf("x: %d visual_height: %d\n", x, data->visual_height[x]);
		x++;
	}
	x = 0;
	y = 0;
	int color = 0x00FF00;
	while (x < WINDOW_WIDTH)
	{
		y = 0;
		while (y < WINDOW_HEIGHT)
		{
			if ((WINDOW_HEIGHT - data->visual_height[x]) / 2 <= y && y <= (WINDOW_HEIGHT + data->visual_height[x]) / 2)
				my_mlx_pixel_put(data, x, y, color);
			// my_mlx_pixel_put(data, x, y, color);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx_utils->mlx, \
		data->mlx_utils->win, data->mlx_utils->img, 0, 0);
}