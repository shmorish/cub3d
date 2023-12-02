/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_to_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:01:42 by hhino             #+#    #+#             */
/*   Updated: 2023/12/02 15:27:08 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/draw.h"

void	get_wall_addr(t_texture	*texture)
{
	texture->south->addr = (int *)mlx_get_data_addr(texture->south->wall_img, \
		&texture->south->bpp, &texture->south->line_length, \
		&texture->south->endian);
	texture->north->addr = (int *)mlx_get_data_addr(texture->north->wall_img, \
		&texture->north->bpp, &texture->north->line_length, \
		&texture->north->endian);
	texture->west->addr = (int *)mlx_get_data_addr(texture->west->wall_img, \
		&texture->west->bpp, &texture->west->line_length, \
		&texture->west->endian);
	texture->east->addr = (int *)mlx_get_data_addr(texture->east->wall_img, \
		&texture->east->bpp, &texture->east->line_length, \
		&texture->east->endian);
}

void	put_file_to_image(t_data *data)
{
	data->texture->west->wall_img = mlx_xpm_file_to_image(data->mlx_utils->mlx, \
			data->parser->west_texture, &data->texture->west->img_w, \
			&data->texture->west->img_h);
	data->texture->east->wall_img = mlx_xpm_file_to_image(data->mlx_utils->mlx, \
			data->parser->east_texture, &data->texture->east->img_w, \
			&data->texture->east->img_h);
	data->texture->south->wall_img = mlx_xpm_file_to_image(data->mlx_utils->mlx,
			data->parser->south_texture, &data->texture->south->img_w, \
			&data->texture->south->img_h);
	data->texture->north->wall_img = mlx_xpm_file_to_image(data->mlx_utils->mlx,
			data->parser->north_texture, &data->texture->north->img_w, \
			&data->texture->north->img_h);
	get_wall_addr(data->texture);
}

unsigned int	calculate_wall_coordinates(t_wall *wall, double wallpos, \
		int visual_height, int y)
{
	unsigned int	color;
	int				txx;
	int				txy;

	txy = y * wall->img_h / visual_height;
	if (txy >= wall->img_h - 4)
		txy = wall->img_h - 4;
	txx = (wallpos * wall->img_w) / 4;
	if (txx >= wall->img_w - 4)
		txx = wall->img_w - 4;
	color = (unsigned int)get_texel_color(wall, txx, txy);
	return (color);
}
