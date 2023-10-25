/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:38:55 by morishitash       #+#    #+#             */
/*   Updated: 2023/10/25 15:19:54 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_ARG_H
# define CHECK_ARG_H

# include "cub3d.h"

// print errors
# define NOFILE_IN_ARG "No file in argument\n"
# define INVALID_FILE_EXT "Invalid file extension\n"

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