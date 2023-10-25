/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:48:08 by morishitash       #+#    #+#             */
/*   Updated: 2023/10/25 16:03:16 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

void	check_map(t_parser *parser)
{
	exist_player(parser->map);
	is_map_closed(parser, parser->start_point_x, parser->start_point_y);
}
