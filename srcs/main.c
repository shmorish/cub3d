/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:35:52 by morishitash       #+#    #+#             */
/*   Updated: 2023/10/24 07:43:22 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_parser(t_parser *parser)
{
	free(parser->north_texture);
	parser->north_texture = NULL;
	free(parser->south_texture);
	parser->south_texture = NULL;
	free(parser->west_texture);
	parser->west_texture = NULL;
	free(parser->east_texture);
	parser->east_texture = NULL;
	free(parser);
	parser = NULL;
}

int	main(int argc, char **argv)
{
	t_data		*data;
	t_parser	*parser;

	(void)parser;
	if (check_args(argc, argv) == INVALID)
		return (1);
	parser = init_parser(argv[1]);
	data = init_data();
	free_parser(parser);
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