/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_judge.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:55:37 by hhino             #+#    #+#             */
/*   Updated: 2023/11/23 15:09:04 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/player.h"

static bool	cannot_go(t_data *data, char **map, double x, double y)
{
	if (map[(int)y][(int)x] == '1' || map[(int)y][(int)x] == ' ')
		return (true);
	else
	{
		data->player_pos_x = x;
		data->player_pos_y = y;
		return (false);
	}
}

void	wall_judge(t_data *data, double x, double y)
{
	double	check_x;
	double	check_y;

	check_x = data->player_pos_x + x;
	check_y = data->player_pos_y + y;
	if (cannot_go(data, data->parser->map, check_x, check_y) == false)
	{
		return ;
	}
	check_x = data->player_pos_x + x;
	check_y = data->player_pos_y;
	if (cannot_go(data, data->parser->map, check_x, check_y) == false)
	{
		return ;
	}
	check_x = data->player_pos_x;
	check_y = data->player_pos_y + y;
	if (cannot_go(data, data->parser->map, check_x, check_y) == false)
	{
		return ;
	}
}
