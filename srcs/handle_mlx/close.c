/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhino <hhino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:32:33 by hhino             #+#    #+#             */
/*   Updated: 2023/11/15 17:02:31 by hhino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/handle_mlx.h"

int	close_window_esc(int keycode, t_data *data)
{
	(void)keycode;
	mlx_destroy_window(data->mlx_utils->mlx, data->mlx_utils->win);
	exit (0);
	return (0);
}

int	close_window_botton(t_data *data)
{
	mlx_destroy_window(data->mlx_utils->mlx, data->mlx_utils->win);
	exit(0);
	return (0);
}
