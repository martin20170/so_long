/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mphilip <mphilip@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:21:55 by mphilip           #+#    #+#             */
/*   Updated: 2023/06/07 14:25:33 by mphilip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_game(t_game *game, char *path)
{
	game->map = get_map(path);
	if (!game->map)
		quit_game(game, 0, 0, -2);
	game->map_cpy = get_map(path);
	if (!game->map_cpy)
		quit_game(game, 0, 1, -2);
	if (map_checker(game) == 0)
		quit_game(game, 0, 1, -1);
	game->win_ptr = mlx_new_window(game->mlx_ptr, get_y_dim(game->map) * 100, \
		get_x_dim(game->map) * 100, "mlx");
	game->imgs = get_imgs(game->mlx_ptr);
	game->x_player = get_x_pos(game->map, 'P');
	game->y_player = get_y_pos(game->map, 'P');
	game->x_exit = get_x_pos(game->map, 'E');
	game->y_exit = get_y_pos(game->map, 'E');
	game->coll_count = coll_count(game->map);
	game->mv_count = 0;
	print_game(game);
}

int	quit_game(t_game *game, int mlx_state, int map_state, int code)
{
	if (map_state == 1)
		free_map(game->map);
	if (mlx_state == 1)
	{
		mlx_destroy_image (game->mlx_ptr, game->imgs.pl);
		mlx_destroy_image (game->mlx_ptr, game->imgs.enmy);
		mlx_destroy_image (game->mlx_ptr, game->imgs.col);
		mlx_destroy_image (game->mlx_ptr, game->imgs.ex);
		mlx_destroy_image (game->mlx_ptr, game->imgs.emp);
		mlx_destroy_image (game->mlx_ptr, game->imgs.wall);
		mlx_destroy_window (game->mlx_ptr, game->win_ptr);
		if (code == 2)
			ft_printf("\n\nYOU WIN !!!\n");
		else if (code == 1)
			ft_printf("\n\nYOU LOOSE :(\n");
		else if (code == 0)
			ft_printf("\n\nYou left the game...\n");
	}
	else if (code == -1)
		ft_printf("!MAP ERROR!\n");
	else
		ft_printf("!MEMORY ALLOCATION ERROR OR MAP NOT EXIST!\n");
	exit(0);
}

int	quit_from_cross(t_game *game)
{
	quit_game(game, 1, 1, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf("Too much arguments, please choose one map.\n");
		return (0);
	}
	game.mlx_ptr = mlx_init();
	set_game(&game, argv[1]);
	mlx_key_hook(game.win_ptr, &move, &game);
	mlx_hook(game.win_ptr, 17, 0, &quit_from_cross, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
