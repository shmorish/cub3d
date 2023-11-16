/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhino <hhino@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 19:35:10 by hhino             #+#    #+#             */
/*   Updated: 2023/11/16 20:01:41 by hhino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include <stdio.h>

int	main()
{
	void	*mlx;
	void	*win;
	void	*img;
	int		img_w;
	int		img_h;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1000, 1000, "test");
	img = mlx_xpm_file_to_image(mlx, "./texture/orca_west.xpm", &img_w, &img_h);
	printf("img:%p\n", img);
	printf("width:%d\n", img_w);
	printf("heigh:%d\n", img_h);
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
