/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 03:04:39 by morishitash       #+#    #+#             */
/*   Updated: 2023/11/09 23:44:34 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

char	**map_parse(char **map)
{
	int		i;
	char	*tmp;
	int		len;

	i = 0;
	if (map == NULL)
		exit(err_msg(NO_MAP_ERR));
	while (map[i] != NULL)
	{
		len = ft_strlen(map[i]);
		if (map[i][len - 1] == '\n')
			len--;
		tmp = ft_substr(map[i], 0, len);
		free(map[i]);
		map[i] = tmp;
		i++;
	}
	return (map);
}
