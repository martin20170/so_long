/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mphilip <mphilip@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:21:55 by mphilip           #+#    #+#             */
/*   Updated: 2023/06/05 14:07:09 by mphilip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


t_imgs	get_imgs(void *mlx_ptr)
{
	t_imgs	result;
	int		pos[2];

	result.empty = mlx_xpm_file_to_image(mlx_ptr, "./textures/empty.xpm", &pos[0], &pos[1]);
	result.wall = mlx_xpm_file_to_image(mlx_ptr, "./textures/wall.xpm", &pos[0], &pos[1]);
	result.collectible = mlx_xpm_file_to_image(mlx_ptr, "./textures/collectible.xpm", &pos[0], &pos[1]);
	result.exit = mlx_xpm_file_to_image(mlx_ptr, "./textures/exit.xpm", &pos[0], &pos[1]);
	result.player = mlx_xpm_file_to_image(mlx_ptr, "./textures/player.xpm", &pos[0], &pos[1]);
	result.enemy = mlx_xpm_file_to_image(mlx_ptr, "./textures/enemy.xpm", &pos[0], &pos[1]);
	return (result);
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
		return(close(fd), NULL);
	result = ft_split(straight_map, '|');
	if (!result)
		return (close(fd), NULL);
	return (free(straight_map), close(fd), result);
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
			if (game->map[i][j] == 'P')
				mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, game->imgs.player, j * 100, i * 100);
			if (game->map[i][j] == 'X')
				mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, game->imgs.enemy, j * 100, i * 100);
			if (game->map[i][j] == 'C')
				mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, game->imgs.collectible, j * 100, i * 100);
			if (game->map[i][j] == 'E')
				mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, game->imgs.exit, j * 100, i * 100);
			if (game->map[i][j] == '0')
				mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, game->imgs.empty, j * 100, i * 100);
			if (game->map[i][j] == '1')
				mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, game->imgs.wall, j * 100, i * 100);
			j++;
		}
		i++;
	}
}

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


void	quit_game(t_game *game, int code)
{
	free_map(game->map);
	mlx_destroy_image (game->mlx_ptr, game->imgs.player);
	mlx_destroy_image (game->mlx_ptr, game->imgs.enemy);
	mlx_destroy_image (game->mlx_ptr, game->imgs.collectible);
	mlx_destroy_image (game->mlx_ptr, game->imgs.exit);
	mlx_destroy_image (game->mlx_ptr, game->imgs.empty);
	mlx_destroy_image (game->mlx_ptr, game->imgs.wall);
	mlx_clear_window (game->mlx_ptr, game->win_ptr );
	mlx_destroy_window (game->mlx_ptr, game->win_ptr);
	if (code == 2)
		ft_printf("YOU WIN !!!\n");
	else if (code == 1)
		ft_printf("YOU LOOSE :(\n");
	else if (code == 0)
		ft_printf("You left the game...\n");
	else
		ft_printf("ERROR\n");
	exit(0);
}

void	set_game(t_game *game)
{
	int	x;

	x = 0;
	while (game->map[x])
		x++;
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, (ft_strlen(game->map[0]) - 1) * 100, x * 100, "mlx");
	game->imgs = get_imgs(game->mlx_ptr);
	print_game(game);
}

int	key_checker(int key)
{
	if(key == 0x0077 || key == 0x0073 || key == 0x0061 || key == 0x0064 || key == 0x0071)
		return (1);
	return (0);
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
	int	x_player;
	int	y_player;
	int	x_enemy;
	int	y_enemy;


	x_player = get_x_pos(game->map, 'P');
	y_player = get_y_pos(game->map, 'P');
	x_enemy = get_x_pos(game->map, 'X');
	y_enemy = get_y_pos(game->map, 'X');
	place_player(key, game, x_player, y_player);
	x_player = get_x_pos(game->map, 'P');
	y_player = get_y_pos(game->map, 'P');
	if (x_player == x_enemy && y_player == y_enemy)
		quit_game(game, 1);
}


int	move(int key, void *param)
{
	t_game	*game;
	game = (t_game *)param;
	(void)game;

	if (key_checker(key) == 1)
	{
		move_player(key, game);
		if (key == 0x0071)
			quit_game(game, 0);
	}
	mlx_clear_window (game->mlx_ptr, game->win_ptr );
	print_game(game);
	return (0);
}

void	running_game(t_game *game)
{
	mlx_key_hook(game->win_ptr, &move, game);
}




int	main(void)
{
	t_game	game;

	game.map = get_map("./maps/map1.ber");
	if (!game.map)
		exit(0);

	set_game(&game);
	running_game(&game);
	mlx_loop(game.mlx_ptr);

	return (0);
}


// cc -Wall -Wextra -Werror -I./minilibx-linux -L./minilibx-linux -o so_long main.c -lmlx -lXext -lX11 -lm
// cc -Wall -Wextra -Werror -I./minilibx_opengl_20191021 -L./minilibx_opengl_20191021 -o so_long main.c -lmlx -framework OpenGL -framework AppKit && ./so_long
