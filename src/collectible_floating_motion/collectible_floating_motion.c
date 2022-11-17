/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible_floating_motion.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 07:53:49 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/17 11:03:07 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	p_collectible(t_game *game, t_idx idx, int count)
{
	if (count % 30 <= 5)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->img.collectible, idx.col * 32, idx.row * 32);
	else if (count % 30 <= 11)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->img.collectible, idx.col * 32, idx.row * 32 + 2);
	else if (count % 30 <= 17)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->img.collectible, idx.col * 32, idx.row * 32 + 4);
	else if (count % 30 <= 23)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->img.collectible, idx.col * 32, idx.row * 32 + 4);
	else if (count % 30 <= 29)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->img.collectible, idx.col * 32, idx.row * 32 + 2);
}

int	collectible_floating_motion(t_game *game)
{
	static int	count;
	t_idx		idx;

	ft_memset(&idx, 0, sizeof(t_idx));
	while (idx.row < game->map_size.row)
	{
		idx.col = 0;
		while (idx.col < game->map_size.col)
		{
			if (game->map[idx.row][idx.col] == COLLECTIBLE)
			{
				p_road(game, idx);
				p_collectible(game, idx, count);
			}
			idx.col++;
		}
		idx.row++;
	}
	count++;
	return (0);
}
