/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:48:05 by morishitash       #+#    #+#             */
/*   Updated: 2023/10/24 07:42:24 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_data(t_data *data)
{
	free(data->mlx_utils);
	data->mlx_utils = NULL;
	free(data->map);
	data->map = NULL;
	free(data);
	data = NULL;
}
