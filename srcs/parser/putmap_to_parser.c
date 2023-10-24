/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putmap_to_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 01:28:22 by morishitash       #+#    #+#             */
/*   Updated: 2023/10/25 03:04:10 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

void	print_map(char **map);

char	**get_map(int fd)
{
	char	**map;
	char	**map_tmp;
	int		height;
	int		i;

	height = 0;
	map_tmp = NULL;
	while (1)
	{
		map = (char **)malloc_err(sizeof(char *) * (height + 2));
		i = 0;
		while (map_tmp != NULL && map_tmp[i] != NULL)
		{
			map[i] = map_tmp[i];
			i++;
		}
		free(map_tmp);
		map[height] = get_next_line(fd);
		map[height + 1] = NULL;
		if (map[height] == NULL)
			break ;
		height++;
		map_tmp = map;
	}
	return (map);
}

void	putmap_to_parser(t_parser *parser, int fd)
{
	parser->map = map_parse(get_map(fd));
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
		printf("map[%d] %p\n", i, map[i]);
		i++;
	}
}
#else

void	print_map(char **map)
{
	(void)map;
}

#endif