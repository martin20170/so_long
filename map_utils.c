/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mphilip <mphilip@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:44:25 by mphilip           #+#    #+#             */
/*   Updated: 2023/06/07 14:03:07 by mphilip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

char	*map_completion(char *incomplete_map, char *to_add)
{
	char	*temp;
	char	*result;

	temp = ft_strjoin(incomplete_map, to_add);
	if (!temp)
		return (NULL);
	result = ft_strjoin(temp, "|");
	if (!result)
		return (NULL);
	free(incomplete_map);
	free(to_add);
	free(temp);
	return (result);
}

char	*get_straight_map(int fd)
{
	char	*temp;
	char	*temp_result;

	temp_result = malloc(1);
	if (!temp_result)
		return (NULL);
	temp_result[0] = 0;
	temp = get_next_line(fd);
	if (!temp)
		return (free(temp_result), NULL);
	while (temp[0])
	{
		temp_result = map_completion(temp_result, temp);
		if (!temp_result)
			return (free(temp), free(temp_result), NULL);
		temp = get_next_line(fd);
		if (!temp)
			return (free(temp), free(temp_result), NULL);
	}
	return (free(temp), temp_result);
}

char	**get_map(char *path)
{
	int		fd;
	char	*straight_map;
	char	**result;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	straight_map = get_straight_map(fd);
	if (!straight_map)
		return (close(fd), NULL);
	result = ft_split(straight_map, '|');
	if (!result)
		return (close(fd), NULL);
	return (free(straight_map), close(fd), result);
}
