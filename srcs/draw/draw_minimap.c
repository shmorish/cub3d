/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:02:12 by morishitash       #+#    #+#             */
/*   Updated: 2023/11/14 14:04:34 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/draw.h"

void	draw_square(t_data *data, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			my_mlx_pixel_put(data, x * 10 + j, y * 10 + i, color);
			j++;
		}
		i++;
	}
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
				draw_square(data, j, i, 0x00FF00);
			else if (data->parser->map[i][j] == '0')
				draw_square(data, j, i, 0x0000FF);
			j++;
		}
		i++;
	}
	draw_square(data, data->player_pos_x, data->player_pos_y, 0xFF0000);
}
