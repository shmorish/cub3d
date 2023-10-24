/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_msg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:43:07 by morishitash       #+#    #+#             */
/*   Updated: 2023/10/25 00:42:04 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/check_arg.h"

int	err_msg(char *msg)
{
	ft_putstr_fd(RED, 2);
	ft_putstr_fd("cub3D: ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(RESET, 2);
	return (1);
}

int	perror_msg(char *msg)
{
	ft_putstr_fd(RED, 2);
	ft_putstr_fd("cub3D: ", 2);
	perror(msg);
	ft_putstr_fd(RESET, 2);
	return (1);
}

void	*malloc_err(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
	{
		err_msg(MALLOC_ERR);
		exit(1);
	}
	return (ptr);
}
