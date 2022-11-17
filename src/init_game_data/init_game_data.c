/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 01:53:05 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/17 11:08:15 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	init_game_data(t_game *game)
{
	init_map_size(game);
	init_map(game);
	init_player_position(game);
	init_collectible_count(game);
	init_mlx_pointer(game);
	init_img_pointer(game);
	init_move_count(game);
}
