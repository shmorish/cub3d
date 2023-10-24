/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 02:30:53 by morishitash       #+#    #+#             */
/*   Updated: 2023/10/25 02:38:44 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

static void	free_map(char **map)
{
	int	i;

	i = 0;
	if (map == NULL)
		return ;
	while (map[i] != NULL)
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
	map = NULL;
}

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
	free_map(parser->map);
	free(parser);
	parser = NULL;
}
