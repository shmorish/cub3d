/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhino <hhino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:45:54 by hhino             #+#    #+#             */
/*   Updated: 2023/11/18 16:09:24 by hhino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "cub3d.h"

# define KEY_PRESS 2
# define KEY_LEFT_ARROW 123
# define KEY_RIGHT_ARROW 124
# define KEY_DOWN_ARROW 125
# define KEY_UP_ARROW 126
# define KEY_ESC 53

# define MOVE_SPEED 0.4
# define KEY_A 0
# define KEY_D 2
# define KEY_S 1
# define KEY_W 13

void	game_in_progress(t_data *data);
void	wall_judge(t_data *data, double x, double y);

#endif
