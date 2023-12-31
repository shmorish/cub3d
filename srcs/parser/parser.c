/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:39:41 by morishitash       #+#    #+#             */
/*   Updated: 2023/12/01 20:39:46 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

void	putdata_to_parser(t_parser *parser);

// map info
// 
// NO: North Wall Texture
// SO: South Wall Texture
// WE: West Wall Texture
// EA: East Wall Texture
// 
// F: Floor color (R,G,B)
// C: Cieling color (R,G,B)
//
// 0: empty
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
	parser->sprite_texture = NULL;
	parser->is_bonus = false;
	parser->floor_color = -1;
	parser->ceiling_color = -1;
	parser->player_dir = UNKNOWN;
	parser->map = NULL;
	putdata_to_parser(parser);
	return (parser);
}

void	putdata_to_parser(t_parser *parser)
{
	int		fd;
	char	*line;

	fd = open(parser->filename, O_RDONLY);
	if (fd == -1)
		exit(err_msg(OPEN_ERR));
	puttexture_to_parser(parser, fd);
	check_texture_path(parser);
	line = get_next_line(fd);
	if (line == NULL || line[0] != '\n')
		exit(err_msg("Invalid map info\n"));
	free(line);
	putcolor_to_parser(parser, fd);
	check_color(parser);
	line = get_next_line(fd);
	if (line == NULL || line[0] != '\n')
		exit(err_msg("Invalid map info\n"));
	free(line);
	putmap_to_parser(parser, fd);
	arrange_map(parser);
	check_map(parser);
	close(fd);
}
