/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:45:54 by hhino             #+#    #+#             */
/*   Updated: 2023/11/13 02:15:21 by morishitash      ###   ########.fr       */
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

# define MOVE_SPEED 0.2
# define KEY_A 0
# define KEY_D 2

void	game_in_progress(t_data *data);

#endif
