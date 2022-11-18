/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 21:38:33 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/18 14:50:47 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	init_list(&game.map_lst);
	parse_map(&game.map_lst, argc, argv);
	init_game_data(&game);
	print_map(&game, game.map_size);
	mlx_hook(game.win_ptr, KEY_PRESS, 0, key_press, &game);
	mlx_hook(game.win_ptr, KEY_EXIT, 0, close_game, &game);
	mlx_loop_hook(game.mlx_ptr, collectible_floating_motion, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
