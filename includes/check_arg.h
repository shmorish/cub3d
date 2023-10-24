/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:38:55 by morishitash       #+#    #+#             */
/*   Updated: 2023/10/25 00:38:23 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_ARG_H
# define CHECK_ARG_H

# include "cub3d.h"

// print errors (used)
# define NOFILE_IN_ARG "No file in argument\n"
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
int		is_directory(char **argv);
int		check_file_invalid(char **argv);
// err_msg.c
int		err_msg(char *msg);
int		perror_msg(char *msg);
void	*malloc_err(size_t size);

#endif