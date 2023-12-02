/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhino <hhino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:03:47 by hhino             #+#    #+#             */
/*   Updated: 2023/12/02 15:14:55 by hhino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "cub3d.h"

typedef struct s_data		t_data;
typedef struct s_wall		t_wall;
typedef struct s_texture	t_texture;

void			draw_floor_sky(t_data *data);
void			draw_wall(t_data *data);
void			draw_minimap(t_data *data);
void			wall_image_to_window(t_data *data, int w, int h);
void			re_draw(t_data *data);

//xpm_to_wall
void			put_file_to_image(t_data *data);
void			get_wall_addr(t_texture *texture);
// unsigned int	calculate_wall_coordinates(t_data *data, t_wall *wall, double wallpos, int x, int y);
unsigned int	calculate_wall_coordinates(t_wall *wall, double wallpos, int visual_height, int y);

#endif
