/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:47:15 by morishitash       #+#    #+#             */
/*   Updated: 2023/10/25 00:42:18 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	print_data_addr(t_data *data);

void	map_init(t_map *map)
{
	map->map_width = 0;
	map->map_height = 0;
	map->map = NULL;
}

t_data	*init_data(void)
{
	t_data	*data;

	data = (t_data *)malloc_err(sizeof(t_data));
	data->mlx_utils = (t_mlx_utils *)malloc_err(sizeof(t_mlx_utils));
	data->map = (t_map *)malloc_err(sizeof(t_map));
	mlx_utils_init(data);
	map_init(data->map);
	print_data_addr(data);
	return (data);
}

#ifdef DEBUG

static void	print_data_addr(t_data *data)
{
	printf("---------------------------\n");
	printf("FILE: %s\n", __FILE__);
	printf("data: %p\n", data);
	printf("data->mlx_utils: %p\n", data->mlx_utils);
	printf("data->map: %p\n", data->map);
}

#else

static void	print_data_addr(t_data *data)
{
	(void)data;
}

#endif
