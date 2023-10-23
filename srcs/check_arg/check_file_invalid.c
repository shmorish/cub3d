/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_invalid.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:07:40 by morishitash       #+#    #+#             */
/*   Updated: 2023/10/23 17:33:26 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/check_arg.h"

static int	check_directory(char **argv)
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
	{
		ft_putstr_fd(RED, 2);
		perror("cub3D");
		ft_putstr_fd(RESET, 2);
		return (INVALID);
	}
	close(fd);
	if (check_directory(argv) == INVALID)
		return (INVALID);
	return (VALID);
}
