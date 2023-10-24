/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 03:04:39 by morishitash       #+#    #+#             */
/*   Updated: 2023/10/25 03:11:24 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

char	**map_parse(char **map)
{
	int		i;
	char	*tmp;

	i = 0;
	if (map == NULL)
		exit(err_msg(NO_MAP_ERR));
	while (map[i] != NULL)
	{
		tmp = ft_substr(map[i], 0, ft_strlen(map[i]) - 1);
		free(map[i]);
		map[i] = tmp;
		i++;
	}
	return (map);
}
