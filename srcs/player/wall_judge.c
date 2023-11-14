/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_judge.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhino <hhino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:55:37 by hhino             #+#    #+#             */
/*   Updated: 2023/11/14 14:06:39 by hhino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/player.h"

void	wall_judge(t_data *data, double x, double y)
{
	bool	no_wall;

	no_wall = false;
	if (data->parser->map[(int)y][(int)x] != '1')
		no_wall = true;
	if (no_wall == true)
	{
		data->player_pos_x = x;
		data->player_pos_y = y;
	}
}
