/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:00:36 by morishitash       #+#    #+#             */
/*   Updated: 2023/10/25 16:03:04 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

void	exist_player(char **map)
{
	int	i;
	int	j;
	int	player_num;

	i = 0;
	player_num = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (is_player(map[i][j]) == true)
				player_num++;
			j++;
		}
		i++;
	}
	if (player_num == 0)
		exit(err_msg(INVALID_MAP_NO_PLAYER));
	else if (player_num > 1)
		exit(err_msg(INVALID_MAP_PLAYER_MSG));
	return ;
}
