/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_player.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 07:31:08 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/17 10:57:49 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	p_player_up(t_game *game, t_idx idx)
{
	p_road(game, idx);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->img.player.up, idx.col * 32, idx.row * 32);
}

void	p_player_down(t_game *game, t_idx idx)
{
	p_road(game, idx);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->img.player.down, idx.col * 32, idx.row * 32);
}

void	p_player_left(t_game *game, t_idx idx)
{
	p_road(game, idx);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->img.player.left, idx.col * 32, idx.row * 32);
}

void	p_player_right(t_game *game, t_idx idx)
{
	p_road(game, idx);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->img.player.right, idx.col * 32, idx.row * 32);
}
