/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:35:52 by morishitash       #+#    #+#             */
/*   Updated: 2023/10/23 23:25:56 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (check_args(argc, argv) == INVALID)
		return (1);
	data = init_data(argv[1]);
	// if (parse_cub(argv[1], data) == INVALID)
	// 	return (1);
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