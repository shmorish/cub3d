/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:38:15 by morishitash       #+#    #+#             */
/*   Updated: 2023/10/23 17:41:38 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/check_arg.h"

int	check_args(int argc, char **argv)
{
	if (argc != 2)
		return (err_msg(NOFILE_IN_ARG), INVALID);
	if (check_file_extension(argv) == INVALID)
		return (INVALID);
	if (check_file_invalid(argv) == INVALID)
		return (INVALID);
	return (VALID);
}
