/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhino <hhino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:35:52 by morishitash       #+#    #+#             */
/*   Updated: 2023/11/08 19:22:16 by hhino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_data		*data;
	t_parser	*parser;

	(void)parser;
	if (check_args(argc, argv) == INVALID)
		return (1);
	parser = init_parser(argv[1]);
	data = init_data();
	data->parser = parser;
	draw_floor_sky(data);
	mlx_hook(data->mlx_utils->win, 17, 0L, close_window_botton, data);
	mlx_hook(data->mlx_utils->win, 2, 1L << 0, close_window_esc, data);
	mlx_loop(data->mlx_utils->mlx);
	free_parser(parser);
	data->parser = NULL;
	free_data(data);
	return (0);
}

#ifdef DEBUG

__attribute__((destructor))
static void	destructor(void)
{
	printf("---------------------------\n");
	system("leaks -q cub3D");
}

#endif
