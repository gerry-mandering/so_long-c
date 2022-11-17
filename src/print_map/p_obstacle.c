/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_obstacle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 07:33:34 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/17 10:35:28 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	p_sign(t_game *game, t_idx idx)
{
	p_road(game, idx);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->img.obstacle[0], idx.col * 32, idx.row * 32);
}

void	p_fence(t_game *game, t_idx idx)
{
	p_road(game, idx);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->img.obstacle[1], idx.col * 32, idx.row * 32);
}

void	p_bush(t_game *game, t_idx idx)
{
	p_road(game, idx);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->img.obstacle[2], idx.col * 32, idx.row * 32);
}

void	p_rock(t_game *game, t_idx idx)
{
	p_road(game, idx);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->img.obstacle[3], idx.col * 32, idx.row * 32);
}
