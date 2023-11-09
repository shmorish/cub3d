/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:00:36 by morishitash       #+#    #+#             */
/*   Updated: 2023/11/10 01:04:37 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

t_direction	get_player_dir(char c)
{
	if (c == 'N')
		return (NORTH);
	else if (c == 'S')
		return (SOUTH);
	else if (c == 'W')
		return (WEST);
	else if (c == 'E')
		return (EAST);
	return (UNKNOWN);
}

void	exist_player(t_parser *parser)
{
	int		i;
	int		j;
	int		player_num;
	char	**map;

	map = parser->map;
	i = -1;
	player_num = 0;
	while (map[++i] != NULL)
	{
		j = -1;
		while (map[i][++j] != '\0')
		{
			if (is_player(map[i][j]) == true)
			{
				parser->player_dir = get_player_dir(map[i][j]);
				player_num++;
			}
		}
	}
	if (player_num == 0)
		exit(err_msg(INVALID_MAP_NO_PLAYER));
	else if (player_num > 1)
		exit(err_msg(INVALID_MAP_PLAYER_MSG));
	return ;
}
