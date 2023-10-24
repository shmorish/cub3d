/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putcolor_to_parser.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 06:49:42 by morishitash       #+#    #+#             */
/*   Updated: 2023/10/24 15:46:27 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

void	putcolor_to_parser(t_parser *parser, int fd)
{
	putfloor_color_to_paraser(parser, fd);
	putceiling_color_to_parser(parser, fd);
}
