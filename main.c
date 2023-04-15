#include "mlx.h"

int	main()
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx");
	mlx_loop(mlx_ptr);

	win_ptr++; //juste pour pas peter les glinches.

	return (0);
}

// cc -Wall -Wextra -Werror -I./minilibx-linux -L./minilibx-linux -o so_long main.c -lmlx -lXext -lX11 -lm
