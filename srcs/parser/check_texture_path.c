/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 07:48:54 by morishitash       #+#    #+#             */
/*   Updated: 2023/11/08 18:24:12 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

void	check_texture_extension(t_parser *parser);

void	check_directory_texture(t_parser *parser)
{
	int	fd;

	fd = open(parser->north_texture, O_DIRECTORY);
	if (fd != -1)
		exit(perror_msg("North texture"));
	close(fd);
	fd = open(parser->south_texture, O_DIRECTORY);
	if (fd != -1)
		exit(perror_msg("South texture"));
	close(fd);
	fd = open(parser->west_texture, O_DIRECTORY);
	if (fd != -1)
		exit(perror_msg("West texture"));
	close(fd);
	fd = open(parser->east_texture, O_DIRECTORY);
	if (fd != -1)
		exit(perror_msg("East texture"));
	close(fd);
	if (parser->is_bonus == true)
	{
		fd = open(parser->sprite_texture, O_DIRECTORY);
		if (fd != -1)
			exit(perror_msg("Sprite texture"));
		close(fd);
	}
}

void	check_texture_path(t_parser *parser)
{
	int	fd;

	fd = open(parser->north_texture, O_RDONLY);
	if (fd == -1)
		exit(perror_msg("North texture"));
	close(fd);
	fd = open(parser->south_texture, O_RDONLY);
	if (fd == -1)
		exit(perror_msg("South texture"));
	close(fd);
	fd = open(parser->west_texture, O_RDONLY);
	if (fd == -1)
		exit(perror_msg("West texture"));
	close(fd);
	fd = open(parser->east_texture, O_RDONLY);
	if (fd == -1)
		exit(perror_msg("East texture"));
	close(fd);
	if (parser->is_bonus == true)
	{
		fd = open(parser->sprite_texture, O_RDONLY);
		if (fd == -1)
			exit(perror_msg("Sprite texture"));
		close(fd);
	}
}
