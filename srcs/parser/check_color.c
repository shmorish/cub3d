/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:41:29 by morishitash       #+#    #+#             */
/*   Updated: 2023/10/24 16:01:52 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

void	print_color(t_parser *parser);

void	check_color(t_parser *parser)
{
	print_color(parser);
	if (parser->floor_color_r < 0 || 255 < parser->floor_color_r)
		exit(err_msg(FLOOR_COLOR_OUT_OF_RANGE));
	if (parser->floor_color_g < 0 || 255 < parser->floor_color_g)
		exit(err_msg(FLOOR_COLOR_OUT_OF_RANGE));
	if (parser->floor_color_b < 0 || 255 < parser->floor_color_b)
		exit(err_msg(FLOOR_COLOR_OUT_OF_RANGE));
	if (parser->ceiling_color_r < 0 || 255 < parser->ceiling_color_r)
		exit(err_msg(CEILING_COLOR_OUT_OF_RANGE));
	if (parser->ceiling_color_g < 0 || 255 < parser->ceiling_color_g)
		exit(err_msg(CEILING_COLOR_OUT_OF_RANGE));
	if (parser->ceiling_color_b < 0 || 255 < parser->ceiling_color_b)
		exit(err_msg(CEILING_COLOR_OUT_OF_RANGE));
}

#ifdef DEGUB

void	print_color(t_parser *parser)
{
	printf("floor_color_r: %d\n", parser->floor_color_r);
	printf("floor_color_g: %d\n", parser->floor_color_g);
	printf("floor_color_b: %d\n", parser->floor_color_b);
	printf("ceiling_color_r: %d\n", parser->ceiling_color_r);
	printf("ceiling_color_g: %d\n", parser->ceiling_color_g);
	printf("ceiling_color_b: %d\n", parser->ceiling_color_b);
}

#else

void	print_color(t_parser *parser)
{
	(void)parser;
}

#endif