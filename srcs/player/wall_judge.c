/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_judge.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:55:37 by hhino             #+#    #+#             */
/*   Updated: 2023/11/16 22:18:32 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/player.h"

void	wall_judge(t_data *data, double x, double y)
{
	bool	no_wall;
	double	check_x;
	double	check_y;

	check_x = data->player_pos_x + x;
	check_y = data->player_pos_y + y;
	no_wall = false;
	if (data->parser->map[(int)check_y][(int)check_x] != '1')
		no_wall = true;
	if (no_wall == true)
	{
		data->player_pos_x = check_x;
		data->player_pos_y = check_y;
		return ;
	}
	check_x = data->player_pos_x + x;
	check_y = data->player_pos_y;
	if (data->parser->map[(int)check_y][(int)check_x] != '1')
		no_wall = true;
	if (no_wall == true)
	{
		data->player_pos_x = check_x;
		data->player_pos_y = check_y;
		return ;
	}
	check_x = data->player_pos_x;
	check_y = data->player_pos_y + y;
	if (data->parser->map[(int)check_y][(int)check_x] != '1')
		no_wall = true;
	if (no_wall == true)
	{
		data->player_pos_x = check_x;
		data->player_pos_y = check_y;
		return ;
	}
}
