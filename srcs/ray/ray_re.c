#include "../includes/ray.h"

void	get_ray_length_x(t_data *data, double dir, t_ray *ray)
{
	int		x;
	double	y;

	x = (int)(data->player_pos_x);
	ray->ray_length = __DBL_MAX__;
	// printf("---this is from x---\n");
	// printf("dir -> %.02f\n", dir / M_PI * 180);
	// printf("pos_now -> %.02f %.02f\n", data->player_pos_x, data->player_pos_y);
	while (1)
	{
		if ((dir < M_PI_2 || dir > M_PI_2 * 3) && x == (int)(data->player_pos_x))
			x++;
		y = tan(dir) * (x - data->player_pos_x) + data->player_pos_y;
		if (x < 0 || y < 0 || x > data->parser->map_width || y > data->parser->map_height)
			return ;
		if (dir < M_PI_2 || dir > M_PI_2 * 3)
		{
			ray->wall = y - (int)y;
			// printf("x -> %d y -> %d map[%d][%d] -> %c\n", (int)x, (int)y, (int)y, (int)x, data->parser->map[(int)y][(int)x]);
			if (data->parser->map[(int)y][x] == '1')
				break ;
			x++;
		}
		else
		{
			ray->wall = 1 - (y - (int)y);
			// printf("x -> %d y -> %d map[%d][%d] -> %c\n", (int)x, (int)y, (int)y, (int)x - 1, data->parser->map[(int)y][(int)x - 1]);
			if (data->parser->map[(int)y][x - 1] == '1')
				break ;
			x--;
		}
	}
	// printf("ray->wall -> %.02f\n", ray->wall);
	// printf("map[%d][%d] -> %c\n", (int)y, x, data->parser->map[(int)y][x]);
	ray->ray_length = sqrt(pow(x - data->player_pos_x, 2) + pow(y - data->player_pos_y, 2)) * cos(dir - data->player_dir);
	// printf("ray->ray_length -> %.02f\n", ray->ray_length);
}

t_ray	*get_length_ray_from_x(t_data *data, double dir)
{
	t_ray	*ray;

	ray = (t_ray *)malloc_err(sizeof(t_ray));
	while (dir < 0)
		dir += 2 * M_PI;
	while (dir > 2 * M_PI)
		dir -= 2 * M_PI;
	get_ray_length_x(data, dir, ray);
	if (dir < M_PI_2 || dir > M_PI_2 * 3)
		ray->dir = EAST;
	else
		ray->dir = WEST;
	return (ray);
}

void	get_ray_length_y(t_data *data, double dir, t_ray *ray)
{
	int		y;
	double	x;

	y = (int)(data->player_pos_y);
	ray->ray_length = __DBL_MAX__;
	// printf("---this is from y---\n");
	// printf("dir -> %.02f\n", dir / M_PI * 180);
	// printf("pos_now -> %.02f %.02f\n", data->player_pos_x, data->player_pos_y);
	while (1)
	{
		if (y == (int)(data->player_pos_y) && (dir < M_PI))
			y++;
		x = ((y - data->player_pos_y) / tan(dir)) + data->player_pos_x;
		if (y < 0 || x < 0 || y > data->parser->map_height || x > data->parser->map_width)
			return ;
		if (dir < M_PI)
		{
			ray->wall = x - (int)x;
			// printf("x -> %d y -> %d map[%d][%d] -> %c\n", (int)x, (int)y, (int)y, (int)x, data->parser->map[(int)y][(int)x]);
			if (data->parser->map[y][(int)x] == '1')
				break ;
			y++;
		}
		else
		{
			ray->wall = 1 - (x - (int)x);
			// printf("x -> %d y -> %d map[%d][%d] -> %c\n", (int)x, (int)y, (int)y - 1, (int)x, data->parser->map[y - 1][(int)x]);
			if (data->parser->map[y - 1][(int)x] == '1')
				break ;
			y--;
		}
	}
	// printf("ray->wall -> %.02f\n", ray->wall);
	// printf("map[%d][%d] -> %c\n", y, (int)x, data->parser->map[y][(int)x]);
	ray->ray_length = sqrt(pow(x - data->player_pos_x, 2) + pow(y - data->player_pos_y, 2)) * cos(dir - data->player_dir);
	// printf("ray->ray_length -> %.02f\n", ray->ray_length);
}

t_ray	*get_length_ray_from_y(t_data *data, double dir)
{
	t_ray	*ray;

	ray = (t_ray *)malloc_err(sizeof(t_ray));
	while (dir < 0)
		dir += 2 * M_PI;
	while (dir > 2 * M_PI)
		dir -= 2 * M_PI;
	get_ray_length_y(data, dir, ray);
	if (dir < M_PI)
		ray->dir = SOUTH;
	else
		ray->dir = NORTH;
	return (ray);
}

void	put_ray_data(t_data	*data)
{
	t_ray	*ray_data_x;
	t_ray	*ray_data_y;
	int		x;

	x = 0;
	while (x <= WINDOW_WIDTH)
	{
		// printf("right_ray -> %.02f\n", (data->right_ray + (M_PI_2 * x / WINDOW_WIDTH)) / M_PI * 180);
		ray_data_x = get_length_ray_from_x(data, data->right_ray + (M_PI_2 * x / WINDOW_WIDTH));
		ray_data_y = get_length_ray_from_y(data, data->right_ray + (M_PI_2 * x / WINDOW_WIDTH));
		if (ray_data_x->ray_length < ray_data_y->ray_length)
		{
			data->length_ray[x] = ray_data_x->ray_length;
			data->wall_dir[x] = ray_data_x->dir;
			data->wall_pos[x] = ray_data_x->wall;
		}
		else
		{
			data->length_ray[x] = ray_data_y->ray_length;
			data->wall_dir[x] = ray_data_y->dir;
			data->wall_pos[x] = ray_data_y->wall;
		}
		free(ray_data_x);
		ray_data_x = NULL;
		free(ray_data_y);
		ray_data_y = NULL;
		x++;
	}
}
