/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mphilip <mphilip@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 21:08:16 by mphilip           #+#    #+#             */
/*   Updated: 2023/06/05 12:32:37 by mphilip          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <unistd.h>
#include "libft/libft.h"

typedef struct s_imgs
{
	void	*empty;
	void	*wall;
	void	*collectible;
	void	*exit;
	void	*player;
	void	*enemy;
}			t_imgs;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_imgs	imgs;
	char	**map;
}			t_game;
