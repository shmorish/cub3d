/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_msg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:43:07 by morishitash       #+#    #+#             */
/*   Updated: 2023/10/23 17:14:20 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/check_arg.h"

void	err_msg(char *msg)
{
	ft_putstr_fd(RED, 2);
	ft_putstr_fd("cub3D: ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(RESET, 2);
}
