/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 07:48:54 by morishitash       #+#    #+#             */
/*   Updated: 2023/10/24 08:08:15 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

void	check_texture_extension(t_parser *parser);

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
	check_texture_extension(parser);
}

void	check_texture_extension(t_parser *parser)
{
	if (ft_strncmp(ft_strrchr(parser->north_texture, '.'), ".xpm", 4) != 0)
		exit(err_msg("North texture extension"));
	if (ft_strncmp(ft_strrchr(parser->south_texture, '.'), ".xpm", 4) != 0)
		exit(err_msg("South texture extension"));
	if (ft_strncmp(ft_strrchr(parser->west_texture, '.'), ".xpm", 4) != 0)
		exit(err_msg("West texture extension"));
	if (ft_strncmp(ft_strrchr(parser->east_texture, '.'), ".xpm", 4) != 0)
		exit(err_msg("East texture extension"));
}
// .xpma とか 弾けてない