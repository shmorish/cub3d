/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morishitashoto <morishitashoto@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:59:08 by morishitash       #+#    #+#             */
/*   Updated: 2023/10/23 23:21:58 by morishitash      ###   ########.fr       */
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

t_data	*init_data(char *filename);
void	free_data(t_data *data);
void	mlx_utils_init(t_data *data);
#endif