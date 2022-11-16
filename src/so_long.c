/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:14:20 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/16 20:51:13 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_character_pack(t_assets *assets, void *mlx_ptr)
{
	assets->character.up[0] = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/character/up_0.xpm", &assets->width, &assets->height);
	assets->character.down[0] = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/character/down_0.xpm", &assets->width, &assets->height);
	assets->character.left[0] = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/character/left_0.xpm", &assets->width, &assets->height);
	assets->character.left[1] = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/character/left_1.xpm", &assets->width, &assets->height);
	assets->character.left[2] = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/character/left_2.xpm", &assets->width, &assets->height);
	assets->character.right[0] = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/character/right_0.xpm", &assets->width, &assets->height);
}

void	init_object_pack(t_assets *assets, void *mlx_ptr)
{
	assets->object.tree_top = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/map/object/tree_up.xpm", &assets->width, &assets->height);
	assets->object.tree_middle = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/map/object/tree_mid.xpm", &assets->width, &assets->height);
	assets->object.tree_bottom = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/map/object/tree_down.xpm", &assets->width, &assets->height);
	assets->object.others[IDX_SIGN] = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/map/object/sign.xpm", &assets->width, &assets->height);
	assets->object.others[IDX_FENCE] = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/map/object/fence.xpm", &assets->width, &assets->height);
	assets->object.others[IDX_BUSH] = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/map/object/bush.xpm", &assets->width, &assets->height);
	assets->object.others[IDX_ROCK] = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/map/object/rock.xpm", &assets->width, &assets->height);
}

void	init_wall_pack(t_assets *assets, void *mlx_ptr)
{
	assets->wall.up_left = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/map/surrounding_wall/up_left.xpm", \
	&assets->width, &assets->height);
	assets->wall.up_center = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/map/surrounding_wall/up_center.xpm", \
	&assets->width, &assets->height);
	assets->wall.up_right = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/map/surrounding_wall/up_right.xpm", \
	&assets->width, &assets->height);
	assets->wall.mid_left = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/map/surrounding_wall/mid_left.xpm", \
	&assets->width, &assets->height);
	assets->wall.mid_right = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/map/surrounding_wall/mid_right.xpm", \
	&assets->width, &assets->height);
	assets->wall.down_left = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/map/surrounding_wall/down_left.xpm", \
	&assets->width, &assets->height);
	assets->wall.down_center = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/map/surrounding_wall/down_center.xpm", \
	&assets->width, &assets->height);
	assets->wall.down_right = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/map/surrounding_wall/down_right.xpm", \
	&assets->width, &assets->height);
}

void	init_assets(t_assets *assets, void *mlx_ptr)
{
	assets->tile = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/map/tile/snow.xpm", &assets->width, &assets->height);
	assets->collectible = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/collectible/box.xpm", &assets->width, &assets->height);
	assets->exit = mlx_xpm_file_to_image(mlx_ptr, \
	"../assets/map/exit/exit.xpm", &assets->width, &assets->height);
	init_character_pack(assets, mlx_ptr);
	init_object_pack(assets, mlx_ptr);
	init_wall_pack(assets, mlx_ptr);
}

void	labeling_corner_wall(t_pack *pack)
{
	char	**arr_map;
	t_coord	*map_size;

	arr_map = pack->arr_map;
	map_size = &pack->map_size;
	arr_map[0][0] = UP_LEFT;
	arr_map[0][map_size->row - 1] = UP_RIGHT;
	arr_map[map_size->col - 1][0] = DOWN_LEFT;
	arr_map[map_size->col - 1][map_size->row - 1] = DOWN_RIGHT;
}

void	labeling_side_wall(t_pack *pack)
{
	int		i;
	char	**arr_map;
	t_coord	*map_size;

	i = 1;
	arr_map = pack->arr_map;
	map_size = &pack->map_size;
	while (i < map_size->col - 1)
	{
		arr_map[i][0] = LEFT_SIDE;
		arr_map[i][map_size->row - 1] = RIGHT_SIDE;
		i++;
	}
	i = 1;
	while (i < map_size->row - 1)
	{
		arr_map[0][i] = UP_SIDE;
		arr_map[map_size->col - 1][i] = DOWN_SIDE;
		i++;
	}
}

void	labeling_surrounding_wall(t_pack *pack)
{
	labeling_corner_wall(pack);
	labeling_side_wall(pack);
}

int	count_continuous_wall(t_pack *pack, t_index index)
{
	char	**arr_map;
	t_coord	*map_size;
	int		count;

	arr_map = pack->arr_map;
	map_size = &pack->map_size;
	count = 0;
	while (index.i < map_size->col - 2)
	{
		if (arr_map[index.i][index.j] == '1')
			count++;
		else
			break ;
		index.i++;
	}
	return (count);
}

void	labeling_single_tree(t_pack *pack, t_index index)
{
	char	**arr_map;
	t_coord	*map_size;

	arr_map = pack->arr_map;
	map_size = &pack->map_size;
	arr_map[index.i][index.j] = TREE_UP;
	arr_map[index.i + 1][index.j] = TREE_DOWN;
}

void	labeling_double_tree(t_pack *pack, t_index index)
{
	char	**arr_map;
	t_coord	*map_size;

	arr_map = pack->arr_map;
	map_size = &pack->map_size;
	arr_map[index.i][index.j] = TREE_UP;
	arr_map[index.i + 1][index.j] = TREE_MID;
	arr_map[index.i + 2][index.j] = TREE_DOWN;
}

void	labeling_tree(t_pack *pack)
{
	t_index	index;
	char	**arr_map;
	t_coord	*map_size;

	index.i = 1;
	arr_map = pack->arr_map;
	map_size = &pack->map_size;
	while (index.i < map_size->col - 2)
	{
		index.j = 0;
		while (index.j < map_size->row - 1)
		{
			if (count_continuous_wall(pack, index) == 2)
				labeling_single_tree(pack, index);
			else if (count_continuous_wall(pack, index) >= 3)
				labeling_double_tree(pack, index);
			index.j++;
		}
		index.i++;
	}
}

char	get_objects_in_order(void)
{
	static int	count;
	const char	arr_objects[4] = {'s', 'd', 'x', 'c'};

	return (arr_objects[count++ % 4]);
}

void	labeling_object(t_pack *pack)
{
	t_index	index;
	char	**arr_map;
	t_coord	*map_size;

	index.i = 1;
	arr_map = pack->arr_map;
	map_size = &pack->map_size;
	while (index.i < map_size->col - 1)
	{
		index.j = 0;
		while (index.j < map_size->row - 1)
		{
			if (arr_map[index.i][index.j] == '1')
				arr_map[index.i][index.j] = get_objects_in_order();
			index.j++;
		}
		index.i++;
	}
}

void	labeling_map(t_pack *pack)
{
	labeling_surrounding_wall(pack);
	labeling_tree(pack);
	labeling_object(pack);
}

void	init_mlx_and_window(t_pack *pack)
{
	pack->ptr.mlx = mlx_init();
	pack->ptr.win = mlx_new_window(pack->ptr.mlx, \
	(pack->map_size.row * 32), (pack->map_size.col * 32), "Merry Christmas");
}

void	init_player_coord(t_pack *pack)
{
	t_index	index;
	char	**arr_map;
	t_coord	*map_size;
	t_coord	*player_coord;

	index.i = 1;
	arr_map = pack->arr_map;
	map_size = &pack->map_size;
	player_coord = &pack->player_coord;
	while (index.i < map_size->col - 1)
	{
		index.j = 0;
		while (index.j < map_size->row - 1)
		{
			if (arr_map[index.i][index.j] == PLAYER)
			{
				player_coord->col = index.i;
				player_coord->row = index.j;
			}
			index.j++;
		}
		index.i++;
	}
}

void	init_pack(t_pack *pack, t_list *list_map)
{
	get_map_size(&(pack->map_size), list_map);
	copy_map_to_arr(&(pack->arr_map), list_map, &(pack->map_size));
	labeling_map(pack);
	init_mlx_and_window(pack);
	init_assets(&(pack->assets), pack->ptr.mlx);
	init_player_coord(pack);
	pack->move_count = 0;
}

int	print_window(t_pack *pack)
{
	static int	count;
	t_index		index;
	char		**arr_map;
	t_coord		*map_size;

	index.i = 0;
	arr_map = pack->arr_map;
	map_size = &pack->map_size;
	while (index.i < map_size->col)
	{
		index.j = 0;
		while (index.j < map_size->row)
		{
			mlx_put_image_to_window(pack->ptr.mlx, pack->ptr.win, pack->assets.tile, index.j * 32, index.i * 32);
			if (arr_map[index.i][index.j] == PLAYER)
				mlx_put_image_to_window(pack->ptr.mlx, pack->ptr.win, pack->assets.character.down[0], index.j * 32, index.i * 32);
			if (arr_map[index.i][index.j] == PLAYER_UP)
				mlx_put_image_to_window(pack->ptr.mlx, pack->ptr.win, pack->assets.character.up[0], index.j * 32, index.i * 32);
			else if (arr_map[index.i][index.j] == PLAYER_DOWN)
				mlx_put_image_to_window(pack->ptr.mlx, pack->ptr.win, pack->assets.character.down[0], index.j * 32, index.i * 32);
			else if (arr_map[index.i][index.j] == PLAYER_LEFT)
				mlx_put_image_to_window(pack->ptr.mlx, pack->ptr.win, pack->assets.character.left[0], index.j * 32, index.i * 32);
			else if (arr_map[index.i][index.j] == PLAYER_RIGHT)
				mlx_put_image_to_window(pack->ptr.mlx, pack->ptr.win, pack->assets.character.right[0], index.j * 32, index.i * 32);
			else if (arr_map[index.i][index.j] == COLLECTIBLE)
			{
				if (count % 10 <= 1)
					mlx_put_image_to_window(pack->ptr.mlx, pack->ptr.win, pack->assets.collectible, index.j * 32, index.i * 32);
				else if (count % 10 <= 3)
					mlx_put_image_to_window(pack->ptr.mlx, pack->ptr.win, pack->assets.collectible, index.j * 32, index.i * 32 + 2);
				else if (count % 10 <= 5)
					mlx_put_image_to_window(pack->ptr.mlx, pack->ptr.win, pack->assets.collectible, index.j * 32, index.i * 32 + 4);
				else if (count % 10 <= 7)
					mlx_put_image_to_window(pack->ptr.mlx, pack->ptr.win, pack->assets.collectible, index.j * 32, index.i * 32 + 4);
				else if (count % 10 <= 9)
					mlx_put_image_to_window(pack->ptr.mlx, pack->ptr.win, pack->assets.collectible, index.j * 32, index.i * 32 + 2);
			}
			else if (arr_map[index.i][index.j] == EXIT)
				mlx_put_image_to_window(pack->ptr.mlx, pack->ptr.win, pack->assets.exit, index.j * 32, index.i * 32);
			else if (arr_map[index.i][index.j] == UP_LEFT)
				mlx_put_image_to_window(pack->ptr.mlx, pack->ptr.win, pack->assets.wall.up_left, index.j * 32, index.i * 32);
			else if (arr_map[index.i][index.j] == UP_RIGHT)
				mlx_put_image_to_window(pack->ptr.mlx, pack->ptr.win, pack->assets.wall.up_right, index.j * 32, index.i * 32);
			else if (arr_map[index.i][index.j] == DOWN_LEFT)
				mlx_put_image_to_window(pack->ptr.mlx, pack->ptr.win, pack->assets.wall.down_left, index.j * 32, index.i * 32);
			else if (arr_map[index.i][index.j] == DOWN_RIGHT)
				mlx_put_image_to_window(pack->ptr.mlx, pack->ptr.win, pack->assets.wall.down_right, index.j * 32, index.i * 32);
			else if (arr_map[index.i][index.j] == LEFT_SIDE)
				mlx_put_image_to_window(pack->ptr.mlx, pack->ptr.win, pack->assets.wall.mid_left, index.j * 32, index.i * 32);
			else if (arr_map[index.i][index.j] == RIGHT_SIDE)
				mlx_put_image_to_window(pack->ptr.mlx, pack->ptr.win, pack->assets.wall.mid_right, index.j * 32, index.i * 32);
			else if (arr_map[index.i][index.j] == UP_SIDE)
				mlx_put_image_to_window(pack->ptr.mlx, pack->ptr.win, pack->assets.wall.up_center, index.j * 32, index.i * 32);
			else if (arr_map[index.i][index.j] == DOWN_SIDE)
				mlx_put_image_to_window(pack->ptr.mlx, pack->ptr.win, pack->assets.wall.down_center, index.j * 32, index.i * 32);
			else if (arr_map[index.i][index.j] == TREE_UP)
				mlx_put_image_to_window(pack->ptr.mlx, pack->ptr.win, pack->assets.object.tree_top, index.j * 32, index.i * 32);
			else if (arr_map[index.i][index.j] == TREE_MID)
				mlx_put_image_to_window(pack->ptr.mlx, pack->ptr.win, pack->assets.object.tree_middle, index.j * 32, index.i * 32);
			else if (arr_map[index.i][index.j] == TREE_DOWN)
				mlx_put_image_to_window(pack->ptr.mlx, pack->ptr.win, pack->assets.object.tree_bottom, index.j * 32, index.i * 32);
			else if (arr_map[index.i][index.j] == SIGN)
				mlx_put_image_to_window(pack->ptr.mlx, pack->ptr.win, pack->assets.object.others[IDX_SIGN], index.j * 32, index.i * 32);
			else if (arr_map[index.i][index.j] == FENCE)
				mlx_put_image_to_window(pack->ptr.mlx, pack->ptr.win, pack->assets.object.others[IDX_FENCE], index.j * 32, index.i * 32);
			else if (arr_map[index.i][index.j] == BUSH)
				mlx_put_image_to_window(pack->ptr.mlx, pack->ptr.win, pack->assets.object.others[IDX_FENCE], index.j * 32, index.i * 32);
			else if (arr_map[index.i][index.j] == ROCK)
				mlx_put_image_to_window(pack->ptr.mlx, pack->ptr.win, pack->assets.object.others[IDX_ROCK], index.j * 32, index.i * 32);
			index.j++;
		}
		index.i++;
	}
	count++;
	return (0);
}

void	game_close(t_pack *pack)
{
	mlx_destroy_window(pack->ptr.mlx, pack->ptr.win);
	ft_exit(NULL, STDOUT_FILENO, EXIT_SUCCESS);
}

void	move_up(t_pack *pack)
{
	char	**arr_map;
	t_coord	*map_size;
	t_coord	*player_coord;

	arr_map = pack->arr_map;
	map_size = &pack->map_size;
	player_coord = &pack->player_coord;
	if (arr_map[player_coord->col - 1][player_coord->row] == ROAD || arr_map[player_coord->col - 1][player_coord->row] == COLLECTIBLE)
	{
		arr_map[player_coord->col][player_coord->row] = ROAD;
		arr_map[player_coord->col - 1][player_coord->row] = PLAYER_UP;
		player_coord->col--;
		pack->move_count++;
		ft_printf("move_count = %d\n", pack->move_count);
	}
	else if (arr_map[player_coord->col - 1][player_coord->row] == EXIT)
		game_close(pack);
	//print_window(pack);
}

void	move_left(t_pack *pack)
{
	char	**arr_map;
	t_coord	*map_size;
	t_coord	*player_coord;

	arr_map = pack->arr_map;
	map_size = &pack->map_size;
	player_coord = &pack->player_coord;
	if (arr_map[player_coord->col][player_coord->row - 1] == ROAD || arr_map[player_coord->col][player_coord->row - 1] == COLLECTIBLE)
	{
		arr_map[player_coord->col][player_coord->row] = ROAD;
		mlx_put_image_to_window(pack->ptr.mlx, pack->ptr.win, pack->assets.tile, player_coord->row * 31, player_coord->col * 32);
		mlx_put_image_to_window(pack->ptr.mlx, pack->ptr.win, pack->assets.tile, player_coord->row * 32, player_coord->col * 32);
		mlx_do_sync(pack->ptr.mlx);
		mlx_put_image_to_window(pack->ptr.mlx, pack->ptr.win, pack->assets.character.left[0], player_coord->row * 32 - 8, player_coord->col * 32);
		mlx_put_image_to_window(pack->ptr.mlx, pack->ptr.win, pack->assets.tile, player_coord->row * 31, player_coord->col * 32);
		mlx_put_image_to_window(pack->ptr.mlx, pack->ptr.win, pack->assets.tile, player_coord->row * 32, player_coord->col * 32);
		mlx_do_sync(pack->ptr.mlx);
		mlx_put_image_to_window(pack->ptr.mlx, pack->ptr.win, pack->assets.character.left[1], player_coord->row * 32 - 16, player_coord->col * 32);
		mlx_put_image_to_window(pack->ptr.mlx, pack->ptr.win, pack->assets.tile, player_coord->row * 31, player_coord->col * 32);
		mlx_put_image_to_window(pack->ptr.mlx, pack->ptr.win, pack->assets.tile, player_coord->row * 32, player_coord->col * 32);
		mlx_do_sync(pack->ptr.mlx);
		mlx_put_image_to_window(pack->ptr.mlx, pack->ptr.win, pack->assets.character.left[2], player_coord->row * 32 - 24, player_coord->col * 32);
		mlx_put_image_to_window(pack->ptr.mlx, pack->ptr.win, pack->assets.tile, player_coord->row * 31, player_coord->col * 32);
		mlx_put_image_to_window(pack->ptr.mlx, pack->ptr.win, pack->assets.tile, player_coord->row * 32, player_coord->col * 32);
		mlx_do_sync(pack->ptr.mlx);
		arr_map[player_coord->col][player_coord->row - 1] = PLAYER_LEFT;
		player_coord->row--;
		pack->move_count++;
		ft_printf("move_count = %d\n", pack->move_count);
	}
	else if (arr_map[player_coord->col][player_coord->row - 1] == EXIT)
		game_close(pack);
	//print_window(pack);
}

void	move_down(t_pack *pack)
{
	char	**arr_map;
	t_coord	*map_size;
	t_coord	*player_coord;

	arr_map = pack->arr_map;
	map_size = &pack->map_size;
	player_coord = &pack->player_coord;
	if (arr_map[player_coord->col + 1][player_coord->row] == ROAD || arr_map[player_coord->col + 1][player_coord->row] == COLLECTIBLE)
	{
		arr_map[player_coord->col][player_coord->row] = ROAD;
		arr_map[player_coord->col + 1][player_coord->row] = PLAYER_DOWN;
		player_coord->col++;
		pack->move_count++;
		ft_printf("move_count = %d\n", pack->move_count);
	}
	else if (arr_map[player_coord->col + 1][player_coord->row] == EXIT)
		game_close(pack);
	//print_window(pack);
}

void	move_right(t_pack *pack)
{
	char	**arr_map;
	t_coord	*map_size;
	t_coord	*player_coord;

	arr_map = pack->arr_map;
	map_size = &pack->map_size;
	player_coord = &pack->player_coord;
	if (arr_map[player_coord->col][player_coord->row + 1] == ROAD || arr_map[player_coord->col][player_coord->row + 1] == COLLECTIBLE)
	{
		arr_map[player_coord->col][player_coord->row] = ROAD;
		arr_map[player_coord->col][player_coord->row + 1] = PLAYER_RIGHT;
		player_coord->row++;
		pack->move_count++;
		ft_printf("move_count = %d\n", pack->move_count);
	}
	else if (arr_map[player_coord->col][player_coord->row + 1] == EXIT)
		game_close(pack);
	//print_window(pack);
}

int	key_press(int keycode, t_pack *pack)
{
	if (keycode == KEY_W)
		move_up(pack);
	else if (keycode == KEY_A)
		move_left(pack);
	else if (keycode == KEY_S)
		move_down(pack);
	else if (keycode == KEY_D)
		move_right(pack);
	else if (keycode == KEY_ESC)
		game_close(pack);
	return (0);
}

int	main(int argc, char **argv)
{
	t_list		list_map;
	t_pack		pack;
	char		**arr;
	t_coord		map_sizeeeee;

	parse_map(&list_map, argc, argv);
	get_map_size(&map_sizeeeee, &list_map);
	copy_map_to_arr(&arr, &list_map, &map_sizeeeee);
	print_map(arr, &map_sizeeeee);
	init_pack(&pack, &list_map);
	print_map(pack.arr_map, &pack.map_size);
	print_window(&pack);
	mlx_hook(pack.ptr.win, KEY_PRESS, 0, key_press, &pack);
	mlx_loop_hook(pack.ptr.mlx, print_window, &pack);
	mlx_loop(pack.ptr.mlx);
	return (0);
}
