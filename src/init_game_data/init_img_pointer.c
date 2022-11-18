/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 03:30:00 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/18 15:41:09 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	init_player_img_pointer(t_game *game, int *width, int *height)
{
	game->img.player.up = mlx_xpm_file_to_image(game->mlx_ptr, \
		"./assets/character/up.xpm", width, height);
	game->img.player.down = mlx_xpm_file_to_image(game->mlx_ptr, \
		"./assets/character/down.xpm", width, height);
	game->img.player.left = mlx_xpm_file_to_image(game->mlx_ptr, \
		"./assets/character/left.xpm", width, height);
	game->img.player.right = mlx_xpm_file_to_image(game->mlx_ptr, \
		"./assets/character/right.xpm", width, height);
}

static void	init_wall_img_pointer(t_game *game, int *width, int *height)
{
	game->img.wall.top_left_corner = mlx_xpm_file_to_image(game->mlx_ptr, \
		"./assets/map/wall/top_left_corner.xpm", width, height);
	game->img.wall.top_right_corner = mlx_xpm_file_to_image(game->mlx_ptr, \
		"./assets/map/wall/top_right_corner.xpm", width, height);
	game->img.wall.bottom_left_corner = mlx_xpm_file_to_image(game->mlx_ptr, \
		"./assets/map/wall/bottom_left_corner.xpm", width, height);
	game->img.wall.bottom_right_corner = mlx_xpm_file_to_image(game->mlx_ptr, \
		"./assets/map/wall/bottom_right_corner.xpm", width, height);
	game->img.wall.top_side = mlx_xpm_file_to_image(game->mlx_ptr, \
		"./assets/map/wall/top_side.xpm", width, height);
	game->img.wall.bottom_side = mlx_xpm_file_to_image(game->mlx_ptr, \
		"./assets/map/wall/bottom_side.xpm", width, height);
	game->img.wall.left_side = mlx_xpm_file_to_image(game->mlx_ptr, \
		"./assets/map/wall/left_side.xpm", width, height);
	game->img.wall.right_side = mlx_xpm_file_to_image(game->mlx_ptr, \
		"./assets/map/wall/right_side.xpm", width, height);
}

static void	init_tree_img_pointer(t_game *game, int *width, int *height)
{
	game->img.tree.top = mlx_xpm_file_to_image(game->mlx_ptr, \
		"./assets/map/obstacle/tree_top.xpm", width, height);
	game->img.tree.mid = mlx_xpm_file_to_image(game->mlx_ptr, \
		"./assets/map/obstacle/tree_mid.xpm", width, height);
	game->img.tree.bottom = mlx_xpm_file_to_image(game->mlx_ptr, \
		"./assets/map/obstacle/tree_bottom.xpm", width, height);
}

static void	init_obstacle_img_pointer(t_game *game, int *width, int *height)
{
	game->img.obstacle[0] = mlx_xpm_file_to_image(game->mlx_ptr, \
		"./assets/map/obstacle/sign.xpm", width, height);
	game->img.obstacle[1] = mlx_xpm_file_to_image(game->mlx_ptr, \
		"./assets/map/obstacle/fence.xpm", width, height);
	game->img.obstacle[2] = mlx_xpm_file_to_image(game->mlx_ptr, \
		"./assets/map/obstacle/bush.xpm", width, height);
	game->img.obstacle[3] = mlx_xpm_file_to_image(game->mlx_ptr, \
		"./assets/map/obstacle/rock.xpm", width, height);
}

void	init_img_pointer(t_game *game)
{
	int	width;
	int	height;

	game->img.road = mlx_xpm_file_to_image(game->mlx_ptr, \
		"./assets/map/tile.xpm", &width, &height);
	game->img.collectible = mlx_xpm_file_to_image(game->mlx_ptr, \
		"./assets/collectible/box.xpm", &width, &height);
	game->img.exit = mlx_xpm_file_to_image(game->mlx_ptr, \
		"./assets/map/exit.xpm", &width, &height);
	init_player_img_pointer(game, &width, &height);
	init_wall_img_pointer(game, &width, &height);
	init_tree_img_pointer(game, &width, &height);
	init_obstacle_img_pointer(game, &width, &height);
}
