/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhino <hhino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:59:08 by morishitash       #+#    #+#             */
/*   Updated: 2023/11/17 19:41:08 by hhino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stddef.h>
# include <limits.h>
# include <stdbool.h>

# include "../mlx/mlx.h"
# include "../libft/includes/libft.h"

# include "check_arg.h"
# include "parser.h"
# include "draw.h"
# include "handle_mlx.h"
# include "ray.h"
# include "player.h"

// print colors
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define MAGENTA "\033[0;35m"
# define CYAN "\033[0;36m"
# define RESET "\033[0m"

// check errors
# define VALID 0
# define INVALID 1

# define MALLOC_ERR "Memory allocation error\n"
# define MINILIBX_ERR "Minilibx error\n"

# define WINDOW_WIDTH 720
# define WINDOW_HEIGHT 480

typedef struct s_mlx_utils	t_mlx_utils;
typedef struct s_data		t_data;
typedef struct s_parser		t_parser;
typedef struct s_texture	t_texture;
typedef struct s_wall		t_wall;

typedef struct s_mlx_utils
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_mlx_utils;

typedef struct s_data
{
	t_mlx_utils	*mlx_utils;
	t_parser	*parser;
	t_texture	*texture;
	double		player_pos_x;
	double		player_pos_y;
	double		player_dir; // 正面方向の角度(ラジアン)
	double		left_ray; // 左端方向の角度(ラジアン)
	double		right_ray; // 右端方向の角度(ラジアン)
	double		*length_ray; // 画面の横幅分のレイの長さ
	int			*visual_height; // 描画する壁の高さ
}	t_data;

typedef enum e_direction
{
	UNKNOWN,
	NORTH,
	WEST,
	SOUTH,
	EAST,
}	t_direction;

typedef struct s_parser
{
	char		*filename;

	char		*north_texture;
	char		*south_texture;
	char		*west_texture;
	char		*east_texture;
	char		*sprite_texture;

	bool		is_bonus;

	int			floor_color;
	int			ceiling_color;

	t_direction	player_dir;
	char		**map;
	int			map_width;
	int			map_height;
	int			start_point_x;
	int			start_point_y;
}	t_parser;

typedef struct s_texture
{
	t_wall	*south;
	t_wall	*north;
	t_wall	*west;
	t_wall	*east;
	int		img_w;
	int		img_h;
}	t_texture;

typedef struct s_wall
{
	void	*wall_img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_wall;

t_data		*init_data(t_parser *parser);
void		free_data(t_data *data);
t_parser	*init_parser(char *filename);

#endif
