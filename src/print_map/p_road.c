/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_road.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 07:30:06 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/17 08:06:23 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	p_road(t_game *game, t_idx idx)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->img.road, idx.col * 32, idx.row * 32);
}
