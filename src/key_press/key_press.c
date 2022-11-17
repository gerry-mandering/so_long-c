/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 07:34:49 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/17 07:41:20 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		move_player_up(game, game->map, &game->player_pos);
	if (keycode == KEY_S)
		move_player_down(game, game->map, &game->player_pos);
	if (keycode == KEY_A)
		move_player_left(game, game->map, &game->player_pos);
	if (keycode == KEY_D)
		move_player_right(game, game->map, &game->player_pos);
	if (keycode == KEY_ESC)
		close_game(game);
	return (0);
}
