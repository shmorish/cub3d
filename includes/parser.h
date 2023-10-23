/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 23:28:14 by morishitash       #+#    #+#             */
/*   Updated: 2023/10/24 07:49:35 by morishitash      ###   ########.fr       */
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

// puttexture_to_parser.c
void	puttexture_to_parser(t_parser *parser);
// check_texture_path.c
void	check_texture_path(t_parser *parser);

#endif