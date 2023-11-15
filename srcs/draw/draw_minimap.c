/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhino <hhino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:02:12 by morishitash       #+#    #+#             */
/*   Updated: 2023/11/15 18:47:09 by hhino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/draw.h"

void	draw_square(t_data *data, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			my_mlx_pixel_put(data, x * 5 + j, y * 5 + i, color);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data->mlx_utils->mlx, \
		data->mlx_utils->win, data->mlx_utils->img, 0, 0);
}

void	draw_minimap(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->parser->map[i] != NULL)
	{
		j = 0;
		while (data->parser->map[i][j] != '\0')
		{
			if (data->parser->map[i][j] == '1')
				draw_square(data, j, i, 0x0000FF);
			else if (data->parser->map[i][j] == '0'\
				|| data->parser->map[i][j] == 'N')
				draw_square(data, j, i, 0xFFFFFF);
			j++;
		}
		i++;
	}
	draw_square(data, data->player_pos_x, data->player_pos_y, 0xFF0000);
}
