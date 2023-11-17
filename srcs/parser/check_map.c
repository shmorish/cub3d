/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmorish <shmorish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:48:08 by morishitash       #+#    #+#             */
/*   Updated: 2023/11/12 17:18:57 by shmorish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

char	**map_copy(char	**map, int map_height)
{
	char	**map_dup;
	int		i;

	i = 0;
	map_dup = (char **)malloc_err(sizeof(char *) * (map_height + 2));
	while (map[i] != NULL)
	{
		map_dup[i] = ft_strdup(map[i]);
		if (map_dup[i] == NULL)
			exit(err_msg(MALLOC_ERR));
		i++;
	}
	map_dup[i] = NULL;
	return (map_dup);
}

static void	free_2d_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	array = NULL;
}

void	check_map(t_parser *parser)
{
	char	**map_dup;

	map_dup = map_copy(parser->map, parser->map_height);
	exist_player(parser);
	is_map_closed(parser, parser->start_point_x,
		parser->start_point_y, map_dup);
	free_2d_array(map_dup);
}
