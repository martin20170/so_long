/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mphilip <mphilip@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:18:45 by mphilip           #+#    #+#             */
/*   Updated: 2023/06/07 14:47:41 by mphilip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_all_map_elements(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\n')
		{
			if (map[i][j] != 'P' && map[i][j] != 'E' && map[i][j] != 'C' && \
				map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'X')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	p_check(char **map)
{
	int	p_count;
	int	i;
	int	j;

	p_count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				p_count++;
			j++;
		}
		i++;
	}
	if (p_count != 1)
		return (0);
	return (1);
}

int	e_check(char **map)
{
	int	e_count;
	int	i;
	int	j;

	e_count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				e_count++;
			j++;
		}
		i++;
	}
	if (e_count != 1)
		return (0);
	return (1);
}

int	c_check(char **map)
{
	int	c_count;
	int	i;
	int	j;

	c_count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				c_count++;
			j++;
		}
		i++;
	}
	if (c_count == 0)
		return (0);
	return (1);
}

int	x_check(char **map)
{
	int	x_count;
	int	i;
	int	j;

	x_count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'X')
				x_count++;
			j++;
		}
		i++;
	}
	return (x_count);
}
