/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mphilip <mphilip@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:00:45 by mphilip           #+#    #+#             */
/*   Updated: 2023/06/07 14:58:07 by mphilip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	place_player(int key, t_game *game, int x, int y)
{
	if (key == 0x0077 && game->map[x - 1][y] != '1')
	{
		game->map[x][y] = '0';
		game->map[x - 1][y] = 'P';
	}
	else if (key == 0x0073 && game->map[x + 1][y] != '1')
	{
		game->map[x][y] = '0';
		game->map[x + 1][y] = 'P';
	}
	else if (key == 0x0061 && game->map[x][y - 1] != '1')
	{
		game->map[x][y] = '0';
		game->map[x][y - 1] = 'P';
	}
	else if (key == 0x0064 && game->map[x][y + 1] != '1')
	{
		game->map[x][y] = '0';
		game->map[x][y + 1] = 'P';
	}
}

void	move_player(int key, t_game *game)
{
	int	x_player_memo;
	int	y_player_memo;
	int	enemy_check;

	x_player_memo = game->x_player;
	y_player_memo = game->y_player;
	enemy_check = x_check(game->map);
	place_player(key, game, game->x_player, game->y_player);
	game->x_player = get_x_pos(game->map, 'P');
	game->y_player = get_y_pos(game->map, 'P');
	game->coll_count = coll_count(game->map);
	if (!(x_player_memo == game->x_player && y_player_memo == game->y_player))
		ft_printf("Moves count : %d\n", ++game->mv_count);
	if (enemy_check == 1 && x_check(game->map) == 0)
		quit_game(game, 1, 1, 1);
	if (game->x_player == game->x_exit && game->y_player == game->y_exit && \
		game->coll_count == 0)
		quit_game(game, 1, 1, 2);
	if (!(game->x_player == game->x_exit && game->y_player == game->y_exit))
		game->map[game->x_exit][game->y_exit] = 'E';
}

int	move(int key, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	move_player(key, game);
	if (key == 0xff1b)
		quit_game(game, 1, 1, 0);
	mlx_clear_window (game->mlx_ptr, game->win_ptr);
	print_game(game);
	return (0);
}
