/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:59:08 by morishitash       #+#    #+#             */
/*   Updated: 2023/10/24 07:30:03 by morishitash      ###   ########.fr       */
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
# include <limits.h>
# include <stdbool.h>

# include "../mlx/mlx.h"
# include "../libft/includes/libft.h"

# include "check_arg.h"
# include "parser.h"

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
typedef struct s_map		t_map;
typedef struct s_data		t_data;
typedef struct s_parser		t_parser;

typedef struct s_mlx_utils
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		win_width;
	int		win_height;
}	t_mlx_utils;

typedef struct s_map
{
	char	**map;
	int		map_width;
	int		map_height;
}	t_map;

typedef struct s_data
{
	t_mlx_utils	*mlx_utils;
	t_map		*map;
}	t_data;

typedef enum e_direction
{
	UNKNOWN,
	NORTH,
	SOUTH,
	WEST,
	EAST
}	t_direction;


typedef struct s_parser
{
	char		*filename;

	char		*north_texture;
	char		*south_texture;
	char		*west_texture;
	char		*east_texture;

	int			floor_color_r;
	int			floor_color_g;
	int			floor_color_b;
	int			ceiling_color_r;
	int			ceiling_color_g;
	int			ceiling_color_b;

	t_direction	player_dir;
	char		**map;
}	t_parser;

t_data		*init_data(void);
void		free_data(t_data *data);
void		mlx_utils_init(t_data *data);
t_parser	*init_parser(char *filename);
#endif