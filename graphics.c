/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mphilip <mphilip@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:54:45 by mphilip           #+#    #+#             */
/*   Updated: 2023/06/07 13:00:30 by mphilip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_imgs	get_imgs(void *mlx_ptr)
{
	t_imgs	r;
	int		pos[2];

	r.emp = mlx_xpm_file_to_image(mlx_ptr, "./tex/emp.xpm", &pos[0], &pos[1]);
	r.wall = mlx_xpm_file_to_image(mlx_ptr, "./tex/wall.xpm", &pos[0], &pos[1]);
	r.col = mlx_xpm_file_to_image(mlx_ptr, "./tex/col.xpm", &pos[0], &pos[1]);
	r.ex = mlx_xpm_file_to_image(mlx_ptr, "./tex/ex.xpm", &pos[0], &pos[1]);
	r.pl = mlx_xpm_file_to_image(mlx_ptr, "./tex/pl.xpm", &pos[0], &pos[1]);
	r.enmy = mlx_xpm_file_to_image(mlx_ptr, "./tex/enmy.xpm", &pos[0], &pos[1]);
	return (r);
}

void	print_object(t_game *game, int i, int j)
{
	if (game->map[i][j] == 'P')
		mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, \
		game->imgs.pl, j * 100, i * 100);
	if (game->map[i][j] == 'X')
		mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, \
		game->imgs.enmy, j * 100, i * 100);
	if (game->map[i][j] == 'C')
		mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, \
		game->imgs.col, j * 100, i * 100);
	if (game->map[i][j] == 'E')
		mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, \
		game->imgs.ex, j * 100, i * 100);
	if (game->map[i][j] == '0')
		mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, \
		game->imgs.emp, j * 100, i * 100);
	if (game->map[i][j] == '1')
		mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, \
		game->imgs.wall, j * 100, i * 100);
}

void	print_game(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (j < (int)(ft_strlen(game->map[i]) - 1))
		{
			print_object(game, i, j);
			j++;
		}
		i++;
	}
}
