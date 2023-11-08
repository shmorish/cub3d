/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhino <hhino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 23:19:37 by morishitash       #+#    #+#             */
/*   Updated: 2023/11/08 18:27:50 by hhino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/handle_mlx.h"

static void	print_mlx_utils_addr(t_data *data);

void	mlx_utils_init(t_data *data)
{
	data->mlx_utils->mlx = mlx_init();
	data->mlx_utils->win = mlx_new_window(data->mlx_utils->mlx, \
			WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d");
	data->mlx_utils->img = mlx_new_image(data->mlx_utils->mlx, \
			WINDOW_WIDTH, WINDOW_HEIGHT);
	data->mlx_utils->addr = mlx_get_data_addr(data->mlx_utils->img, \
		&data->mlx_utils->bits_per_pixel, &data->mlx_utils->line_length, \
		&data->mlx_utils->endian);
	if (data->mlx_utils->mlx == NULL || data->mlx_utils->win == NULL)
		exit(err_msg(MALLOC_ERR));
	print_mlx_utils_addr(data);
	mlx_hook(data->mlx_utils->win, 17, 1L << 2, close_window_botton, &data);
	mlx_hook(data->mlx_utils->win, 2, 1L << 0, close_window_esc, &data);
}

#ifdef DEBUG

static void	print_mlx_utils_addr(t_data *data)
{
	printf("---------------------------\n");
	printf("FILE: %s\n", __FILE__);
	printf("data->mlx_utils->mlx: %p\n", data->mlx_utils->mlx);
	printf("data->mlx_utils->win: %p\n", data->mlx_utils->win);
}

#else

static void	print_mlx_utils_addr(t_data *data)
{
	(void)data;
}

#endif
