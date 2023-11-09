/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:52:34 by morishitash       #+#    #+#             */
/*   Updated: 2023/11/09 20:43:01 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

#ifdef DEBUG

void	print_texture(t_parser *parser)
{
	printf("---------------------------\n");
	printf("FILE: %s\n", __FILE__);
	printf("parser->north_texture:	%p\n", parser->north_texture);
	printf("parser->south_texture:	%p\n", parser->south_texture);
	printf("parser->west_texture:	%p\n", parser->west_texture);
	printf("parser->east_texture:	%p\n", parser->east_texture);
	printf("parser->sprite_texture:	%p\n", parser->sprite_texture);
	printf("north_texture:	[%s]\n", parser->north_texture);
	printf("south_texture:	[%s]\n", parser->south_texture);
	printf("west_texture:	[%s]\n", parser->west_texture);
	printf("east_texture:	[%s]\n", parser->east_texture);
	printf("sprite_texture:	[%s]\n", parser->sprite_texture);
}

#else

void	print_texture(t_parser *parser)
{
	(void)parser;
}

#endif