# So_long

**so_long** is a very small 2D game, made in C language. This project is aimed at handling graphic libraries and implementing basic gameplay.

you can read the subject [here](https://github.com/madebypixel02/so_long/blob/main/en.subject.pdf)

## Quick Demo

![title](https://user-images.githubusercontent.com/104122065/221467678-c133bb87-0212-46a9-b608-5b5c54906f65.gif)   


# Description

The player's goal is to collect every collectible present on the map, then escape chosing the shortest possible route.
- The program has to take as parameter a map description file ending with the `.ber` extension.
- The player should be able to move in these 4 directions(up, down, left, right) using the W, S, A and D keys.
- The player should not be able to move into walls.

## Map

 - The map has to be constructed with 3 components: **walls**, **collectibles**, and **free space**.
- The map can be composed of only these 5 characters.
  - **0** for an empty space
  - **1** for a wall
  - **C** for a collectible
  - **E** for a map exit
  - **P** for the player's starting position
- The map must be rectangular and must be closed/surrounded by walls.

### map example

```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

## MiniLibX

**MiniLibX** is a tiny graphics library which allows you to do the most basic things for rendering something in screens without any knowlege of X-Window.

you can find more about MiniLibX [here](https://harm-smits.github.io/42docs/libs/minilibx)   

# Ideas

### Map Validation

```C
void	flood_fill(char **map, int row, int col, const t_idx map_size)
{
	if (row < 0 || col < 0)
		return ;
	else if (row == map_size.row || col == map_size.col)
		return ;
	else if (map[row][col] == C_WALL || map[row][col] == C_FLOODED)
		return ;
	map[row][col] = C_FLOODED;
	flood_fill(map, row - 1, col, map_size);
	flood_fill(map, row + 1, col, map_size);
	flood_fill(map, row, col - 1, map_size);
	flood_fill(map, row, col + 1, map_size);
}
```

To ensure that the player can access all collectibles of the map, the program should flood the entire map from the player's location using **FloodFill Algorithm**. After flooding the map, it should be checked for any unflooded collectibles or exits. If collectibles or exits remain unflooded, it indicates that the player cannot access those areas. Therefore, the program should exit cleanly and return an error message.

### Player Movement

If the player presses the W, S, A, or D keys, the program should update the player location on the map. To draw the player's movement on the screen, the previous player location should be overlapped with the tile texture, and the player texture should be redrawn on the player location.

To trigger a key press event and move the player, the `mlx_hook` function in MiniLibX can be used.

```C
mlx_hook(void *win_ptr, int x_event, int x_mask, int (*funct)(), void *param);
```

# Compilation

```sh
$ git clone https://github.com/gerry-mandering/so_long-c.git
$ cd so_long-c
$ make all
```

## Usage

Give **map description file** to `./so_long` using command line arguments.
```sh
$ ./so_long ./maps/valid/map_middle.ber

$ ./so_long ./maps/valid/map_large1.ber
```

## Directory Tree
<details>
<summary>Directory Tree</summary>
<pre>
.
├── Makefile
├── README.md
├── assets
│   ├── character
│   │   ├── down.xpm
│   │   ├── left.xpm
│   │   ├── right.xpm
│   │   └── up.xpm
│   ├── collectible
│   │   └── box.xpm
│   └── map
│       ├── exit.xpm
│       ├── obstacle
│       │   ├── bush.xpm
│       │   ├── fence.xpm
│       │   ├── rock.xpm
│       │   ├── sign.xpm
│       │   ├── tree_bottom.xpm
│       │   ├── tree_mid.xpm
│       │   └── tree_top.xpm
│       ├── tile.xpm
│       └── wall
│           ├── bottom_left_corner.xpm
│           ├── bottom_right_corner.xpm
│           ├── bottom_side.xpm
│           ├── left_side.xpm
│           ├── right_side.xpm
│           ├── top_left_corner.xpm
│           ├── top_right_corner.xpm
│           └── top_side.xpm
├── includes
│   └── so_long.h
├── library
│   ├── doubly_linked_list
│   │   ├── Makefile
│   │   ├── includes
│   │   │   └── doubly_linked_list.h
│   │   └── src
│   │       ├── list_basic.c
│   │       ├── list_clear.c
│   │       └── list_push_pop.c
│   ├── ft_printf
│   │   ├── Makefile
│   │   ├── includes
│   │   │   └── ft_printf.h
│   │   └── src
│   │       ├── branch_c.c
│   │       ├── branch_di.c
│   │       ├── branch_di_util1.c
│   │       ├── branch_di_util2.c
│   │       ├── branch_di_util3.c
│   │       ├── branch_p.c
│   │       ├── branch_p_util1.c
│   │       ├── branch_s.c
│   │       ├── branch_type.c
│   │       ├── branch_u.c
│   │       ├── branch_u_util1.c
│   │       ├── branch_u_util2.c
│   │       ├── branch_x.c
│   │       ├── branch_x_util1.c
│   │       ├── branch_x_util2.c
│   │       ├── branch_x_util3.c
│   │       ├── ft_printf.c
│   │       ├── judgement_functions.c
│   │       ├── libft_functions.c
│   │       ├── parse_funcions.c
│   │       └── string_util_functions.c
│   ├── get_next_line
│   │   ├── Makefile
│   │   ├── includes
│   │   │   └── get_next_line.h
│   │   └── src
│   │       ├── get_next_line.c
│   │       └── get_next_line_utils.c
│   ├── libft
│   │   ├── Makefile
│   │   ├── includes
│   │   │   └── libft.h
│   │   └── src
│   │       ├── ft_atoi.c
│   │       ├── ft_bzero.c
│   │       ├── ft_calloc.c
│   │       ├── ft_close.c
│   │       ├── ft_exit.c
│   │       ├── ft_free.c
│   │       ├── ft_isalnum.c
│   │       ├── ft_isalpha.c
│   │       ├── ft_isascii.c
│   │       ├── ft_isdigit.c
│   │       ├── ft_isprint.c
│   │       ├── ft_isspace.c
│   │       ├── ft_itoa.c
│   │       ├── ft_malloc.c
│   │       ├── ft_memchr.c
│   │       ├── ft_memcmp.c
│   │       ├── ft_memcpy.c
│   │       ├── ft_memmove.c
│   │       ├── ft_memset.c
│   │       ├── ft_open.c
│   │       ├── ft_putchar_fd.c
│   │       ├── ft_putendl_fd.c
│   │       ├── ft_putnbr_fd.c
│   │       ├── ft_putstr_fd.c
│   │       ├── ft_split.c
│   │       ├── ft_strchr.c
│   │       ├── ft_strdup.c
│   │       ├── ft_striteri.c
│   │       ├── ft_strjoin.c
│   │       ├── ft_strlcat.c
│   │       ├── ft_strlcpy.c
│   │       ├── ft_strlen.c
│   │       ├── ft_strmapi.c
│   │       ├── ft_strncmp.c
│   │       ├── ft_strnstr.c
│   │       ├── ft_strrchr.c
│   │       ├── ft_strtrim.c
│   │       ├── ft_substr.c
│   │       ├── ft_tolower.c
│   │       └── ft_toupper.c
│   └── mlx
│       ├── Makefile
│       ├── font.c
│       ├── font.xcf
│       ├── mlx.h
│       ├── mlx_init_loop.m
│       ├── mlx_int.h
│       ├── mlx_int_str_to_wordtab.c
│       ├── mlx_mouse.m
│       ├── mlx_new_image.m
│       ├── mlx_new_window.h
│       ├── mlx_new_window.m
│       ├── mlx_opengl.h
│       ├── mlx_opengl.m
│       ├── mlx_png.c
│       ├── mlx_png.h
│       ├── mlx_rgb.c
│       ├── mlx_shaders.c
│       └── mlx_xpm.c
├── maps
│   ├── not_valid
│   │   ├── duplicate_exit.ber
│   │   ├── duplicate_player.ber
│   │   ├── empty_file.ber
│   │   ├── no_collectible.ber
│   │   ├── no_exit.ber
│   │   ├── no_player.ber
│   │   ├── no_rectangular_shape.ber
│   │   ├── no_surrounding_wall.ber
│   │   ├── no_valid_path1.ber
│   │   ├── no_valid_path2.ber
│   │   └── wrong_components.ber
│   └── valid
│       ├── map_large0.ber
│       ├── map_large1.ber
│       ├── map_middle.ber
│       ├── map_small.ber
│       └── no_road_but_valid_map.ber
└── src
    ├── collectible_floating_motion
    │   └── collectible_floating_motion.c
    ├── init_game_data
    │   ├── init_collectible_count.c
    │   ├── init_game_data.c
    │   ├── init_img_pointer.c
    │   ├── init_map.c
    │   ├── init_map_size.c
    │   ├── init_mlx_pointer.c
    │   ├── init_move_count.c
    │   ├── init_player_position.c
    │   └── map_labeling
    │       ├── labeling_collectible.c
    │       ├── labeling_exit.c
    │       ├── labeling_obstacle.c
    │       ├── labeling_player.c
    │       ├── labeling_road.c
    │       ├── labeling_tree.c
    │       └── labeling_wall.c
    ├── key_press
    │   ├── close_game.c
    │   ├── key_press.c
    │   └── move_player.c
    ├── map_utils
    │   ├── copy_map_to_char_array.c
    │   ├── free_char_map.c
    │   └── get_map_size.c
    ├── parse_map
    │   ├── parse_map.c
    │   ├── validate_components.c
    │   ├── validate_map.c
    │   ├── validate_path.c
    │   ├── validate_rectangular_shape.c
    │   └── validate_surrounding_wall.c
    ├── print_map
    │   ├── p_corner.c
    │   ├── p_exit.c
    │   ├── p_obstacle.c
    │   ├── p_player.c
    │   ├── p_road.c
    │   ├── p_side.c
    │   ├── p_tree.c
    │   └── print_map.c
    └── so_long.c

</pre>
</details>

## Texture Source

- Background Snow and Wall, Obstacles texture by Stealthix [link](https://stealthix.itch.io/rpg-nature-tileset)   
- Player Santa texture by Pipoya [link](https://pipoya.itch.io/pipoya-free-rpg-character-sprites-32x32)   

