/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:38:55 by morishitash       #+#    #+#             */
/*   Updated: 2023/10/23 17:33:57 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_ARG_H
# define CHECK_ARG_H

# include "cub3d.h"

// print errors (used)
# define INVALID_ARG "Invalid argument\n"
# define INVALID_FILE_EXT "Invalid file extension\n"
// print errors (not used)
# define INVALID_MAP "Invalid map\n"
# define INVALID_MAP_MSG "Map is not surrounded by walls\n"
# define INVALID_MAP_CHAR "Map has invalid characters\n"
# define INVALID_MAP_PLAYER_MSG "Map has more than one player\n"
# define INVALID_MAP_NO_PLAYER "Map has no player\n"

// check_arg.c
int		check_args(int argc, char **argv);
// check_file_extension.c
int		check_file_extension(char **argv);
// check_file_invalid.c
int		check_file_invalid(char **argv);
// err_msg.c
void	err_msg(char *msg);

#endif