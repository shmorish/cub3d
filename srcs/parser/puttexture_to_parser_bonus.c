/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puttexture_to_parser_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 06:53:03 by morishitash       #+#    #+#             */
/*   Updated: 2023/11/08 17:55:08 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

static void	check_texture_declaration(t_parser *parser);
static void	substr_texture_path(t_parser *parser);

void	puttexture_to_parser(t_parser *parser, int fd)
{
	parser->north_texture = get_next_line(fd);
	if (parser->north_texture == NULL)
		exit(err_msg(NO_NORTH_TEXTURE_ERR));
	parser->south_texture = get_next_line(fd);
	if (parser->south_texture == NULL)
		exit(err_msg(NO_SOUTH_TEXTURE_ERR));
	parser->west_texture = get_next_line(fd);
	if (parser->west_texture == NULL)
		exit(err_msg(NO_WEST_TEXTURE_ERR));
	parser->east_texture = get_next_line(fd);
	if (parser->east_texture == NULL)
		exit(err_msg(NO_EAST_TEXTURE_ERR));
	parser->sprite_texture = get_next_line(fd);
	if (parser->sprite_texture == NULL)
		exit(err_msg(NO_SPRITE_TEXTURE_ERR));
	check_texture_declaration(parser);
	substr_texture_path(parser);
	print_texture(parser);
}

static void	check_texture_declaration(t_parser *parser)
{
	if (ft_strncmp(parser->north_texture, "NO ", 3) != 0)
		exit(err_msg(NO_NORTH_TEXTURE_ERR));
	if (ft_strncmp(parser->south_texture, "SO ", 3) != 0)
		exit(err_msg(NO_SOUTH_TEXTURE_ERR));
	if (ft_strncmp(parser->west_texture, "WE ", 3) != 0)
		exit(err_msg(NO_WEST_TEXTURE_ERR));
	if (ft_strncmp(parser->east_texture, "EA ", 3) != 0)
		exit(err_msg(NO_EAST_TEXTURE_ERR));
	if (ft_strncmp(parser->sprite_texture, "S ", 2) != 0)
		exit(err_msg(NO_SPRITE_TEXTURE_ERR));
}

static char	*free_replace(char *return_str, char *free_str)
{
	if (return_str == NULL)
		exit(err_msg(MALLOC_ERR));
	free(free_str);
	return (return_str);
}

static void	substr_texture_path(t_parser *parser)
{
	parser->north_texture = free_replace(ft_substr(parser->north_texture, 3,
				ft_strlen(parser->north_texture) - 4), parser->north_texture);
	parser->south_texture = free_replace(ft_substr(parser->south_texture, 3,
				ft_strlen(parser->south_texture) - 4), parser->south_texture);
	parser->west_texture = free_replace(ft_substr(parser->west_texture, 3,
				ft_strlen(parser->west_texture) - 4), parser->west_texture);
	parser->east_texture = free_replace(ft_substr(parser->east_texture, 3,
				ft_strlen(parser->east_texture) - 4), parser->east_texture);
	parser->sprite_texture = free_replace(ft_substr(parser->sprite_texture, 2,
				ft_strlen(parser->sprite_texture) - 3), parser->sprite_texture);
	if (parser->north_texture == NULL || parser->south_texture == NULL
		|| parser->west_texture == NULL || parser->east_texture == NULL
		|| parser->sprite_texture == NULL)
		exit(err_msg(MALLOC_ERR));
}
