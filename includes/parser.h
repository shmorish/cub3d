/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 23:28:14 by morishitash       #+#    #+#             */
/*   Updated: 2023/10/25 16:08:06 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "cub3d.h"

typedef struct s_parser		t_parser;

// put texture error
# define OPEN_ERR "Failed to open the file.\n"
# define NO_NORTH_TEXTURE_ERR "No north texture.\n"
# define NO_SOUTH_TEXTURE_ERR "No south texture.\n"
# define NO_WEST_TEXTURE_ERR "No west texture.\n"
# define NO_EAST_TEXTURE_ERR "No east texture.\n"
// check texture extension error
# define NORTH_TEXT_EXT_ERR "North texture extension is not correct.\n"
# define SOUTH_TEXT_EXT_ERR "South texture extension is not correct.\n"
# define WEST_TEXT_EXT_ERR "West texture extension is not correct.\n"
# define EAST_TEXT_EXT_ERR "East texture extension is not correct.\n"
// check color
# define NO_FLOOR_COLOR_ERR "No floor color.\n"
# define INVALD_FLOOR_COLOR_ERR "Invalid floor color.\n"
# define NO_CEILING_COLOR_ERR "No ceiling color.\n"
# define INVALD_CEILING_COLOR_ERR "Invalid ceiling color.\n"
# define FLOOR_COLOR_OUT_OF_RANGE "Floor color is out of range.\n"
# define CEILING_COLOR_OUT_OF_RANGE "Ceiling color is out of range.\n"
// check map
# define NO_MAP_ERR "No map.\n"
# define INVALID_MAP_MSG "Map is not surrounded by walls\n"
# define INVALID_MAP_PLAYER_MSG "Map has more than one player\n"
# define INVALID_MAP_NO_PLAYER "Map has no player\n"
// not used
# define INVALID_MAP_CHAR "Map has invalid characters\n"

// free_parser.c
void	free_parser(t_parser *parser);
// puttexture_to_parser.c
void	puttexture_to_parser(t_parser *parser, int fd);
// check_texture_path.c
void	check_texture_path(t_parser *parser);
// putcolor_to_parser.c
void	putcolor_to_parser(t_parser *parser, int fd);
// putcolor_ceiling.c
void	putceiling_color_to_parser(t_parser *parser, int fd);
// putcolor_floor.c
void	putfloor_color_to_paraser(t_parser *parser, int fd);
// check_color.c
void	check_color(t_parser *parser);
// putmap_to_parser.c
void	putmap_to_parser(t_parser *parser, int fd);
// map_parse.c
char	**map_parse(char **map);
// get_map_data.c
int		get_map_height(char **map);
int		get_map_width(char **map);
// check_map.c
void	check_map(t_parser *parser);
// check_player.c
void	exist_player(char **map);
// check_map_closed.c
void	is_map_closed(t_parser *parser, int check_x, int check_y);
// get_start_point.c
int		get_start_point_x(char **map);
int		get_start_point_y(char **map);
// is_player.c
bool	is_player(char c);
#endif