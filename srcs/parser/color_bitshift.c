/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bitshift.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 01:13:21 by morishitash       #+#    #+#             */
/*   Updated: 2023/11/07 02:15:14 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

int	color_bitshift(int r, int g, int b)
{
	if (r < 0 || 255 < r || g < 0 || 255 < g || b < 0 || 255 < b)
		exit(err_msg(COLOR_OUT_OF_RANGE));
	return (r << 16 | g << 8 | b);
}
