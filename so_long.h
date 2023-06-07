/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mphilip <mphilip@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 21:08:16 by mphilip           #+#    #+#             */
/*   Updated: 2023/06/07 14:55:39 by mphilip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_imgs
{
	void	*emp;
	void	*wall;
	void	*col;
	void	*ex;
	void	*pl;
	void	*enmy;
}			t_imgs;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_imgs	imgs;
	char	**map;
	char	**map_cpy;
	int		x_player;
	int		y_player;
	int		x_exit;
	int		y_exit;
	int		coll_count;
	int		mv_count;
}			t_game;


/* ###################### MAP UTILS ###################### */


void	free_map(char **map);
char	**get_map(char *path);
char	*get_straight_map(int fd);
char	*map_completion(char *incomplete_map, char *to_add);


/* ###################### MAP CHECKER ###################### */


int		dim_check(char **map);
int		map_checker(t_game *game);
int		diffusion_result(char **map);
void	map_diffusion(char **map, int x, int y);
int		border_check(char **map, int x_dim, int y_dim);


/* ###################### MAP CHECKER UTILS ###################### */


int		p_check(char **map);
int		e_check(char **map);
int		c_check(char **map);
int		x_check(char **map);
int		check_all_map_elements(char **map);


/* ###################### GRAPHICS ###################### */


t_imgs	get_imgs(void *mlx_ptr);
void	print_game(t_game *game);
void	print_game(t_game *game);


/* ###################### EVENTS ###################### */


int		move(int key, void *param);
void	move_player(int key, t_game *game);
void	place_player(int key, t_game *game, int x, int y);


/* ###################### UTILS ###################### */


int		get_x_dim(char **map);
int		get_y_dim(char **map);
int		coll_count(char **map);
int		get_x_pos(char **map, char c);
int		get_y_pos(char **map, char c);


/* ###################### MAIN ###################### */


int		quit_from_cross(t_game *game);

void	set_game(t_game *game, char *path);
int		quit_game(t_game *game, int mlx_state, int map_state, int code);

#endif
