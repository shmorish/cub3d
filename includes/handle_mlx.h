/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mlx.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhino <hhino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:39:24 by hhino             #+#    #+#             */
/*   Updated: 2023/11/22 18:49:40 by hhino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLE_MLX_H
# define HANDLE_MLX_H

# include "cub3d.h"

typedef struct s_data		t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	my_mlx_pixel_put_double(t_data *data, double x, double y, int color);
void	my_mlx_pixel_put_for_wall(t_data *data, int x, int y, int color);

int		close_window_esc(int keycode, t_data *data);
int		close_window_botton(t_data *data);

void	mlx_utils_init(t_data *data);

#endif
