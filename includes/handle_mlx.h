/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mlx.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:39:24 by hhino             #+#    #+#             */
/*   Updated: 2023/11/17 00:11:06 by morishitash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLE_MLX_H
# define HANDLE_MLX_H

# include "cub3d.h"

typedef struct s_data		t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	my_mlx_pixel_put_double(t_data *data, double x, double y, int color);

int		close_window_esc(int keycode, t_data *data);
int		close_window_botton(t_data *data);

void	mlx_utils_init(t_data *data);

#endif
