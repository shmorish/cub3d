/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_invalid.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:07:40 by morishitash       #+#    #+#             */
/*   Updated: 2023/10/24 08:03:13 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/check_arg.h"

int	is_directory(char **argv)
{
	int	fd;

	fd = open(argv[1], O_DIRECTORY);
	if (fd != -1)
	{
		ft_putstr_fd(RED, 2);
		ft_putstr_fd("cub3D: ", 2);
		ft_putstr_fd(argv[1], 2);
		ft_putstr_fd(" Is a directory\n", 2);
		ft_putstr_fd(RESET, 2);
		return (INVALID);
	}
	close(fd);
	return (VALID);
}

// Check the file invalid
// not exist or not readable
int	check_file_invalid(char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (perror_msg(argv[1]));
	close(fd);
	if (is_directory(argv) == INVALID)
		return (INVALID);
	return (VALID);
}
