/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmorish <shmorish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 20:43:41 by shmorish          #+#    #+#             */
/*   Updated: 2023/11/02 20:38:18 by shmorish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

void    arrange_map(t_parser *parser)
{
    char    **map_dup;
    int     i;
    char    *tmp;
    int     len;

    i = 0;
    map_dup = map_copy(parser->map, parser->map_height);
    while (map_dup[i] != NULL)
    {
        len = ft_strlen(map_dup[i]);
        if (len != parser->map_width)
        {
            tmp = (char *)malloc((sizeof(char)) * parser->map_width + 1);
            ft_memcpy(tmp, map_dup[i], len);
            while (len < parser->map_width + 1)
            {
                tmp[len++] = ' ';
            }
            tmp[len] = '\0';
            free(map_dup[i]);
            map_dup[i] = tmp;
        }
        i++;
    }
    free_map(parser->map);
    parser->map = map_dup;
}