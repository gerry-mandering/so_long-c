/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_side.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 07:32:16 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/17 08:06:52 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	p_top_side(t_game *game, t_idx idx)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->img.wall.top_side, idx.col * 32, idx.row * 32);
}

void	p_bottom_side(t_game *game, t_idx idx)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->img.wall.bottom_side, idx.col * 32, idx.row * 32);
}

void	p_left_side(t_game *game, t_idx idx)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->img.wall.left_side, idx.col * 32, idx.row * 32);
}

void	p_right_side(t_game *game, t_idx idx)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
		game->img.wall.right_side, idx.col * 32, idx.row * 32);
}
