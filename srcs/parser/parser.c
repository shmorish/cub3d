/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:39:41 by morishitash       #+#    #+#             */
/*   Updated: 2023/10/25 14:47:59 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

void	putdata_to_parser(t_parser *parser);

// map 情報
// 
// NO: 北向きの壁のテクスチャ
// SO: 南向きの壁のテクスチャ
// WE: 西向きの壁のテクスチャ
// EA: 東向きの壁のテクスチャ
// 
// F: 床の色 (R,G,B)
// C: 天井の色 (R,G,B)
//
// 0: enpty
// 1: wall
// N: player (N,S,W,E)
t_parser	*init_parser(char *filename)
{
	t_parser	*parser;

	parser = (t_parser *)malloc_err(sizeof(t_parser));
	parser->filename = filename;
	parser->north_texture = NULL;
	parser->south_texture = NULL;
	parser->west_texture = NULL;
	parser->east_texture = NULL;
	parser->floor_color_r = -1;
	parser->floor_color_g = -1;
	parser->floor_color_b = -1;
	parser->ceiling_color_r = -1;
	parser->ceiling_color_g = -1;
	parser->ceiling_color_b = -1;
	parser->player_dir = UNKNOWN;
	parser->map = NULL;
	putdata_to_parser(parser);
	return (parser);
}

void	putdata_to_parser(t_parser *parser)
{
	int	fd;

	fd = open(parser->filename, O_RDONLY);
	if (fd == -1)
		exit(err_msg(OPEN_ERR));
	puttexture_to_parser(parser, fd);
	check_texture_path(parser);
	putcolor_to_parser(parser, fd);
	check_color(parser);
	putmap_to_parser(parser, fd);
	check_map(parser);
	close(fd);
}
