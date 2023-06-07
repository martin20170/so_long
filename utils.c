/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mphilip <mphilip@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:59:09 by mphilip           #+#    #+#             */
/*   Updated: 2023/06/06 16:59:51 by mphilip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_x_dim(char **map)
{
	int	x;

	x = 0;
	while (map[x])
		x++;
	return (x);
}

int	get_y_dim(char **map)
{
	return (ft_strlen(map[0]) - 1);
}

int	get_x_pos(char **map, char c)
{
	int	x;

	x = 0;
	while (!ft_strchr(map[x], c))
		x++;
	return (x);
}

int	get_y_pos(char **map, char c)
{
	int	x;
	int	y;

	x = get_x_pos(map, c);
	y = 0;
	while (map[x][y] != c)
		y++;
	return (y);
}

int	coll_count(char **map)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\n')
		{
			if (map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}
