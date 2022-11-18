/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 07:51:31 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/18 14:24:00 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	ft_exit(NULL, STDOUT_FILENO, EXIT_SUCCESS);
	return (0);
}
