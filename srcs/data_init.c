/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmorish <shmorish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:47:15 by morishitash       #+#    #+#             */
/*   Updated: 2023/11/07 19:03:29 by shmorish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	print_data_addr(t_data *data);

t_data	*init_data(void)
{
	t_data	*data;

	data = (t_data *)malloc_err(sizeof(t_data));
	data->mlx_utils = (t_mlx_utils *)malloc_err(sizeof(t_mlx_utils));
	mlx_utils_init(data);
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
}

#else

static void	print_data_addr(t_data *data)
{
	(void)data;
}

#endif
