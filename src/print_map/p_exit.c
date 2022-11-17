/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_exit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 07:30:39 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/17 10:35:15 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	p_exit(t_game *game, t_idx idx)
{
	p_road(game, idx);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->img.exit, idx.col * 32, idx.row * 32);
}
