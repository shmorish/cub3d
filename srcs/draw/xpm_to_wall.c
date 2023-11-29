/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_to_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhino <hhino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:01:42 by hhino             #+#    #+#             */
/*   Updated: 2023/11/29 19:34:30 by hhino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/draw.h"

void	get_wall_addr(t_data *data)
{
	data->texture->south->addr = (int *)mlx_get_data_addr(data->texture->south->wall_img,
		&data->texture->south->bpp, &data->texture->south->line_length,
		&data->texture->south->endian);
	data->texture->north->addr = (int *)mlx_get_data_addr(data->texture->north->wall_img,
		&data->texture->north->bpp, &data->texture->north->line_length,
		&data->texture->north->endian);
	data->texture->west->addr = (int *)mlx_get_data_addr(data->texture->west->wall_img,
		&data->texture->west->bpp, &data->texture->west->line_length,
		&data->texture->west->endian);
	data->texture->east->addr = (int *)mlx_get_data_addr(data->texture->east->wall_img,
		&data->texture->east->bpp, &data->texture->east->line_length,
		&data->texture->east->endian);
}

void	put_file_to_image(t_data *data)
{
	data->texture->west->wall_img = mlx_xpm_file_to_image(data->mlx_utils->mlx,
		data->parser->west_texture, &data->texture->west->img_w,
		&data->texture->west->img_h);
	data->texture->east->wall_img = mlx_xpm_file_to_image(data->mlx_utils->mlx,
		data->parser->east_texture, &data->texture->east->img_w,
		&data->texture->east->img_h);
	data->texture->south->wall_img = mlx_xpm_file_to_image(data->mlx_utils->mlx,
		data->parser->south_texture, &data->texture->south->img_w,
		&data->texture->south->img_h);
	data->texture->north->wall_img = mlx_xpm_file_to_image(data->mlx_utils->mlx,
		data->parser->north_texture, &data->texture->north->img_w,
		&data->texture->north->img_h);
	get_wall_addr(data);
}

unsigned int	calculate_wall_coordinates(t_data *data, t_wall *wall, double x)
{
	unsigned int	color;
	int				txx;
	int				txy;

	(void)data;
	color = 0;
	txy = 0;
	if (x == 1)
		x -= 0.000001;
	txx = x * wall->img_w;
	color = (unsigned int)get_texel_color(wall, txx, txy);
	return (color);
}
