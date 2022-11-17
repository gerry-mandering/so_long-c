/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_corner.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 07:31:47 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/17 10:03:43 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	p_top_left_corner(t_game *game, t_idx idx)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->img.wall.top_left_corner, idx.col * 32, idx.row * 32);
}

void	p_top_right_corner(t_game *game, t_idx idx)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->img.wall.top_right_corner, idx.col * 32, idx.row * 32);
}

void	p_bottom_left_corner(t_game *game, t_idx idx)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->img.wall.bottom_left_corner, idx.col * 32, idx.row * 32);
}

void	p_bottom_right_corner(t_game *game, t_idx idx)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->img.wall.bottom_right_corner, idx.col * 32, idx.row * 32);
}
