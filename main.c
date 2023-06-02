/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mphilip < mphilip@student.42lyon.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:21:55 by mphilip           #+#    #+#             */
/*   Updated: 2023/06/02 14:17:48 by mphilip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdio.h>

void	draw_rectangle(void *mlx_ptr, void *win_ptr)
{
	int	i;
	int	j;

	i = 0;
	while (i < 50)
	{
		j = 0;
		while (j < 100)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, i, j, 0xFFFFFF);
			mlx_loop(mlx_ptr);
			j++;
		}
		i++;
	}
}

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int	pos[2];

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 10000, 10000, "mlx");
	img_ptr = mlx_xpm_file_to_image(mlx_ptr, "one.xpm", &pos[0], &pos[1]);

	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);

	mlx_loop(mlx_ptr);

	return (0);
}

// cc -Wall -Wextra -Werror -I./minilibx-linux -L./minilibx-linux -o so_long main.c -lmlx -lXext -lX11 -lm
// cc -Wall -Wextra -Werror -I./minilibx_opengl_20191021 -L./minilibx_opengl_20191021 -o so_long main.c -lmlx -framework OpenGL -framework AppKit && ./so_long
