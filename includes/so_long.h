/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:14:39 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/15 21:29:08 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../library/libft/includes/libft.h"
# include "../library/ft_printf/includes/ft_printf.h"
# include "../library/get_next_line/includes/get_next_line.h"
# include "../library/mlx/mlx.h"
# include "../library/doubly_linked_list/includes/doubly_linked_list.h"

# define KEY_PRESS		2
# define KEY_RELEASE	3

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

# define NOT_EXIST		0
# define EXIST			1

# define IDX_SIGN		0
# define IDX_FENCE		1
# define IDX_BUSH		2
# define IDX_ROCK		3

# define PLAYER			'P'
# define COLLECTIBLE	'C'
# define EXIT			'E'

# define UP_LEFT		'q'
# define UP_RIGHT		'p'
# define DOWN_LEFT		'z'
# define DOWN_RIGHT		'm'

# define LEFT_SIDE		'a'
# define RIGHT_SIDE		'l'
# define UP_SIDE		't'
# define DOWN_SIDE		'v'

# define TREE_UP		'u'
# define TREE_MID		'j'
# define TREE_DOWN		'n'

# define SIGN			's'
# define FENCE			'd'
# define BUSH			'x'
# define ROCK			'c'

typedef struct s_ptr
{
	void	*mlx;
	void	*win;
}	t_ptr;

typedef struct s_index
{
	int	i;
	int	j;
}	t_index;

typedef struct s_components
{
	int	wall;
	int	collectibles;
	int	exit;
	int	starting_position;
}	t_components;

typedef struct s_coord
{
	int	col;
	int	row;
}	t_coord;

struct s_character
{
	void	*up[3];
	void	*down[3];
	void	*left[3];
	void	*right[3];
};

struct s_wall
{
	void	*up_left;
	void	*up_center;
	void	*up_right;
	void	*mid_left;
	void	*mid_right;
	void	*down_left;
	void	*down_center;
	void	*down_right;
};

struct s_object
{
	void	*tree_top;
	void	*tree_middle;
	void	*tree_bottom;
	void	*others[4];
};

typedef struct s_assets
{
	struct s_wall		wall;
	void				*tile;
	struct s_character	character;
	struct s_object		object;
	void				*collectible;
	void				*exit;
	int					width;
	int					height;
}	t_assets;

typedef struct s_pack
{
	t_coord		map_size;
	char		**arr_map;
	t_ptr		ptr;
	t_assets	assets;
}	t_pack;

// map_util
void	copy_map_to_arr(char ***arr_map, t_list *list_map, t_coord *map_size);
void	get_map_size(t_coord *map_size, t_list *list_map);
//FIX!!!
void	print_map(char **arr_map, t_coord *map_size);

// parse_map
void	parse_map(t_list *list_map, int argc, char **argv);
void	validate_map(t_list *list_map);
void	validate_rectangular_shape(t_list *list_map);
void	validate_components(t_list *list_map);
void	validate_surrounding_wall(t_list *list_map);
void	validate_path(t_list *list_map);

#endif
