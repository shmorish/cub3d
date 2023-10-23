/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_extension.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:02:19 by morishitash       #+#    #+#             */
/*   Updated: 2023/10/23 17:07:08 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/check_arg.h"

// Check the file is .cub file
int	check_file_extension(char **argv)
{
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub", 4) != 0)
	{
		err_msg(INVALID_FILE_EXT);
		return (INVALID);
	}
	return (VALID);
}