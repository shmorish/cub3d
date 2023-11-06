/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:41:29 by morishitash       #+#    #+#             */
/*   Updated: 2023/11/07 01:57:46 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

void	print_color(t_parser *parser);

void	check_color(t_parser *parser)
{
	print_color(parser);
	if (parser->floor_color < 0 || 16777216 < parser->floor_color)
		exit(err_msg(FLOOR_COLOR_OUT_OF_RANGE));
	if (parser->ceiling_color < 0 || 16777216 < parser->ceiling_color)
		exit(err_msg(CEILING_COLOR_OUT_OF_RANGE));
}

#ifdef DEBUG

void	print_color(t_parser *parser)
{
	printf("---------------------------\n");
	printf("FILE: %s\n", __FILE__);
	printf("floor_color:	%X\n", parser->floor_color);
	printf("ceiling_color:	%X\n", parser->ceiling_color);
}

#else

void	print_color(t_parser *parser)
{
	(void)parser;
}

#endif