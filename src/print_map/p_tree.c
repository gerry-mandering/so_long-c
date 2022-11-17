/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_tree.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 07:33:13 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/17 10:35:42 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	p_tree_top(t_game *game, t_idx idx)
{
	p_road(game, idx);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->img.tree.top, idx.col * 32, idx.row * 32);
}

void	p_tree_mid(t_game *game, t_idx idx)
{
	p_road(game, idx);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->img.tree.mid, idx.col * 32, idx.row * 32);
}

void	p_tree_bottom(t_game *game, t_idx idx)
{
	p_road(game, idx);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->img.tree.bottom, idx.col * 32, idx.row * 32);
}
