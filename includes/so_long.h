/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 21:39:11 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/17 11:09:47 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../library/mlx/mlx.h"
# include "../library/libft/includes/libft.h"
# include "../library/ft_printf/includes/ft_printf.h"
# include "../library/get_next_line/includes/get_next_line.h"
# include "../library/doubly_linked_list/includes/doubly_linked_list.h"

// define KEY
# define KEY_PRESS				2
# define KEY_RELEASE			3
# define KEY_W					13
# define KEY_S					1
# define KEY_A					0
# define KEY_D					2
# define KEY_ESC				53

# define NOT_EXIST				0
# define EXIST					1

# define C_ROAD					'0'
# define C_WALL					'1'
# define C_COLLECTIBLE			'C'
# define C_EXIT					'E'
# define C_PLAYER				'P'
# define C_FLOODED				'F'

# define COLLECTIBLE			100

# define TOTAL_LABELS			18

// define Basic Map Label
# define ROAD					0
# define EXIT					1
# define PLAYER					2

// define Wall Label
# define TOP_LEFT_CORNER		3
# define TOP_RIGHT_CORNER		4
# define BOTTOM_LEFT_CORNER		5
# define BOTTOM_RIGHT_CORNER	6
# define TOP_SIDE				7
# define BOTTOM_SIDE			8
# define LEFT_SIDE				9
# define RIGHT_SIDE				10

// define Tree Label
# define TREE_TOP				11
# define TREE_MID				12
# define TREE_BOTTOM			13

// define Obstacle Label
# define SIGN					14
# define FENCE					15
# define BUSH					16
# define ROCK					17

// define Player Label
# define PLAYER_UP				50
# define PLAYER_DOWN			51
# define PLAYER_LEFT			52
# define PLAYER_RIGHT			53

typedef struct s_idx
{
	int	row;
	int	col;
}	t_idx;

// validate_components
typedef struct s_components
{
	int	wall;
	int	collectible;
	int	exit;
	int	player;
}	t_components;

typedef struct s_player
{
	void	*up;
	void	*down;
	void	*left;
	void	*right;
}	t_player;

typedef struct s_wall
{
	void	*top_left_corner;
	void	*top_right_corner;
	void	*bottom_left_corner;
	void	*bottom_right_corner;
	void	*top_side;
	void	*bottom_side;
	void	*left_side;
	void	*right_side;
}	t_wall;

typedef struct s_tree
{
	void	*top;
	void	*mid;
	void	*bottom;
}	t_tree;

typedef struct s_img
{
	void		*road;
	void		*collectible;
	void		*exit;
	t_player	player;
	t_wall		wall;
	t_tree		tree;
	void		*obstacle[4];
}	t_img;

typedef struct s_game
{
	t_list	map_lst;
	t_idx	map_size;
	int		**map;
	t_idx	player_pos;
	int		collectible_count;
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_idx	img_size;
	int		move_count;
}	t_game;

typedef void	(*t_print_label_fp)(t_game *game, t_idx idx) ;

// map_utils
t_idx	get_map_size(t_list *map_lst);
char	**copy_map_to_char_array(t_list *map_lst, const t_idx map_size);
void	free_char_map(char **map, const t_idx map_size);

// parse_map
void	parse_map(t_list *map_lst, int argc, char **argv);
void	validate_map(t_list *map_lst);
void	validate_rectangular_shape(t_list *map_lst, const t_idx map_size);
void	validate_components(char **map, const t_idx map_size);
void	validate_surrounding_wall(char **map, const t_idx map_size);
void	validate_path(char **map, const t_idx map_size);

// init_game_data
void	init_game_data(t_game *game);
void	init_map_size(t_game *game);
void	init_map(t_game *game);
void	init_player_position(t_game *game);
void	init_collectible_count(t_game *game);
void	init_mlx_pointer(t_game *game);
void	init_img_pointer(t_game *game);
void	init_move_count(t_game *game);

// map_labeling
void	labeling_road(int **map, t_list *map_lst);
void	labeling_collectible(int **map, t_list *map_lst);
void	labeling_exit(int **map, t_list *map_lst);
void	labeling_player(int **map, t_list *map_lst);
void	labeling_wall(int **map, t_idx map_size);
void	labeling_tree(int **map, t_list *map_lst, t_idx map_size);
void	labeling_obstacle(int **map, t_list *map_lst);

// print_map
void	print_map(t_game *game, t_idx map_size);
void	p_road(t_game *game, t_idx idx);
void	p_exit(t_game *game, t_idx idx);
void	p_player_up(t_game *game, t_idx idx);
void	p_player_down(t_game *game, t_idx idx);
void	p_player_left(t_game *game, t_idx idx);
void	p_player_right(t_game *game, t_idx idx);
void	p_top_left_corner(t_game *game, t_idx idx);
void	p_top_right_corner(t_game *game, t_idx idx);
void	p_bottom_left_corner(t_game *game, t_idx idx);
void	p_bottom_right_corner(t_game *game, t_idx idx);
void	p_top_side(t_game *game, t_idx idx);
void	p_bottom_side(t_game *game, t_idx idx);
void	p_left_side(t_game *game, t_idx idx);
void	p_right_side(t_game *game, t_idx idx);
void	p_tree_top(t_game *game, t_idx idx);
void	p_tree_mid(t_game *game, t_idx idx);
void	p_tree_bottom(t_game *game, t_idx idx);
void	p_sign(t_game *game, t_idx idx);
void	p_fence(t_game *game, t_idx idx);
void	p_bush(t_game *game, t_idx idx);
void	p_rock(t_game *game, t_idx idx);

// key press
int		key_press(int keycode, t_game *game);
void	move_player_up(t_game *game, int **map, t_idx *player_pos);
void	move_player_down(t_game *game, int **map, t_idx *player_pos);
void	move_player_left(t_game *game, int **map, t_idx *player_pos);
void	move_player_right(t_game *game, int **map, t_idx *player_pos);
void	close_game(t_game *game);

// collectible_floating_motion
int		collectible_floating_motion(t_game *game);

#endif
