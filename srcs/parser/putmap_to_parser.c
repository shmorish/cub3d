/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putmap_to_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 01:28:22 by morishitash       #+#    #+#             */
/*   Updated: 2023/11/09 23:40:06 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

char	**get_map(int fd)
{
	char	**map;
	char	**map_tmp;
	int		height;
	int		i;

	height = 0;
	map_tmp = NULL;
	while (1)
	{
		map = (char **)malloc_err(sizeof(char *) * (height + 2));
		i = 0;
		while (map_tmp != NULL && map_tmp[i] != NULL)
		{
			map[i] = map_tmp[i];
			i++;
		}
		free(map_tmp);
		map[height] = get_next_line(fd);
		if (map[height] == NULL)
			break ;
		map[height + 1] = NULL;
		height++;
		map_tmp = map;
	}
	return (map);
}

void	putmap_to_parser(t_parser *parser, int fd)
{
	parser->map = map_parse(get_map(fd));
	parser->map_height = get_map_height(parser->map);
	parser->map_width = get_map_width(parser->map);
	parser->start_point_x = get_start_point_x(parser->map);
	parser->start_point_y = get_start_point_y(parser->map);
	if (parser->start_point_x == -1 || parser->start_point_y == -1)
		err_msg(INVALID_MAP_NO_PLAYER);
}
