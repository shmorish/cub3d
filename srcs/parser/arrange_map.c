/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmorish <shmorish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:43:41 by shmorish          #+#    #+#             */
/*   Updated: 2023/11/12 17:18:33 by shmorish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

void	print_map(char **map);

void	arrange_map(t_parser *parser)
{
	char	**map_dup;
	int		i;
	int		len;
	char	*tmp;

	i = -1;
	map_dup = map_copy(parser->map, parser->map_height);
	while (map_dup[++i] != NULL)
	{
		len = ft_strlen(map_dup[i]);
		if (len != parser->map_width)
		{
			tmp = (char *)malloc((sizeof(char)) * (parser->map_width + 1));
			ft_memcpy(tmp, map_dup[i], len);
			while (len < parser->map_width)
				tmp[len++] = ' ';
			tmp[len] = '\0';
			free(map_dup[i]);
			map_dup[i] = tmp;
		}
	}
	free_map(parser->map);
	parser->map = map_dup;
	print_map(parser->map);
}

#ifdef DEBUG

void	print_map(char **map)
{
	int	i;

	i = 0;
	printf("---------------------------\n");
	printf("FILE: %s\n", __FILE__);
	printf("map %p\n", map);
	while (map[i] != NULL)
	{
		printf("map[%d]		%p\n", i, map[i]);
		i++;
	}
	printf("---------------------------\n");
	i = 0;
	while (map[i] != NULL)
	{
		printf("map[%d]		[%s]\n", i, map[i]);
		i++;
	}
}
#else

void	print_map(char **map)
{
	(void)map;
}

#endif
