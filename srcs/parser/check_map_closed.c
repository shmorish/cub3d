/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_closed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:18:03 by morishitash       #+#    #+#             */
/*   Updated: 2023/10/25 22:38:41 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

void	is_map_closed(t_parser *parser, int check_x, int check_y, char **map)
{
	if (check_x < 0 || check_y < 0)
		exit(err_msg(INVALID_MAP_MSG));
	if (map[check_y] == NULL)
		exit(err_msg(INVALID_MAP_MSG));
	if (map[check_y][check_x] == '\0')
		exit(err_msg(INVALID_MAP_MSG));
	if (check_x == parser->map_width || check_y == parser->map_height)
		exit(err_msg(INVALID_MAP_MSG));
	if (map[check_y][check_x] == '1')
		return ;
	if (map[check_y][check_x] == ' ')
		exit(err_msg(INVALID_MAP_MSG));
	map[check_y][check_x] = '1';
	is_map_closed(parser, check_x + 1, check_y, map);
	is_map_closed(parser, check_x - 1, check_y, map);
	is_map_closed(parser, check_x, check_y + 1, map);
	is_map_closed(parser, check_x, check_y - 1, map);
}
