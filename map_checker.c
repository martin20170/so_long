/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mphilip <mphilip@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:50:51 by mphilip           #+#    #+#             */
/*   Updated: 2023/06/07 14:46:51 by mphilip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	dim_check(char **map)
{
	int	i;
	int	memo_len;

	i = 0;
	memo_len = ft_strlen(map[0]);
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) != memo_len)
			return (0);
		i++;
	}
	return (1);
}

int	border_check(char **map, int x_dim, int y_dim)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\n')
		{
			if (i == 0 || i == x_dim - 1)
			{
				if (map[i][j] != '1')
					return (0);
			}
			else if (j == 0 || j == y_dim - 1)
			{
				if (map[i][j] != '1')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	map_diffusion(char **map, int x, int y)
{
	if (map[x][y] == '0' || map[x][y] == 'P' || \
		map[x][y] == 'E' || map[x][y] == 'C')
	{
		map[x][y] = '*';
		map_diffusion(map, x + 1, y);
		map_diffusion(map, x - 1, y);
		map_diffusion(map, x, y + 1);
		map_diffusion(map, x, y - 1);
	}
}

int	diffusion_result(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\n')
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	map_checker(t_game *game)
{
	if (*(game->map) == 0)
		return (free_map(game->map_cpy), 0);
	if (dim_check(game->map_cpy) == 0)
		return (free_map(game->map_cpy), 0);
	if (border_check(game->map_cpy, get_x_dim(game->map_cpy), \
		get_y_dim(game->map_cpy)) == 0)
		return (free_map(game->map_cpy), 0);
	if (check_all_map_elements(game->map_cpy) == 0)
		return (free_map(game->map_cpy), 0);
	if (p_check(game->map_cpy) == 0 || e_check(game->map_cpy) == 0 || \
		c_check(game->map_cpy) == 0 || x_check(game->map_cpy) > 1)
		return (free_map(game->map_cpy), 0);
	map_diffusion(game->map_cpy, get_x_pos(game->map_cpy, 'P'), \
		get_y_pos(game->map_cpy, 'P'));
	if (diffusion_result(game->map_cpy) == 0)
		return (free_map(game->map_cpy), 0);
	return (free_map(game->map_cpy), 1);
}
