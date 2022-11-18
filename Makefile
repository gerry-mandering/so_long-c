# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 15:02:00 by minseok2          #+#    #+#              #
#    Updated: 2022/11/18 18:21:21 by minseok2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm
RMFLAGS = -rf
MLXFLAGS = -framework OpenGL -framework Appkit

LIBFT_DIR = library/libft
LIBFT_NAME = ft
LIBPRINTF_DIR = library/ft_printf
LIBPRINTF_NAME = printf
LIBGNL_DIR = library/get_next_line
LIBGNL_NAME = gnl
LIBMLX_DIR = library/mlx
LIBMLX_NAME = mlx
LIBDLL_DIR = library/doubly_linked_list
LIBDLL_NAME = dll

# mandatory
HEADER_DIR = includes

SRCS_DIR = src
SRCS = so_long.c \
	   map_utils/copy_map_to_char_array.c \
	   map_utils/free_char_map.c \
	   map_utils/get_map_size.c \
	   parse_map/parse_map.c \
	   parse_map/validate_map.c \
	   parse_map/validate_rectangular_shape.c \
	   parse_map/validate_components.c \
	   parse_map/validate_surrounding_wall.c \
	   parse_map/validate_path.c \
	   init_game_data/init_game_data.c \
	   init_game_data/init_map_size.c \
	   init_game_data/init_map.c \
	   init_game_data/init_player_position.c \
	   init_game_data/init_collectible_count.c \
	   init_game_data/init_mlx_pointer.c \
	   init_game_data/init_img_pointer.c \
	   init_game_data/init_move_count.c \
	   init_game_data/map_labeling/labeling_road.c \
	   init_game_data/map_labeling/labeling_collectible.c \
	   init_game_data/map_labeling/labeling_exit.c \
	   init_game_data/map_labeling/labeling_player.c \
	   init_game_data/map_labeling/labeling_wall.c \
	   init_game_data/map_labeling/labeling_tree.c \
	   init_game_data/map_labeling/labeling_obstacle.c \
	   print_map/print_map.c \
	   print_map/p_road.c \
	   print_map/p_exit.c \
	   print_map/p_player.c \
	   print_map/p_corner.c \
	   print_map/p_side.c \
	   print_map/p_tree.c \
	   print_map/p_obstacle.c \
	   key_press/key_press.c \
	   key_press/move_player.c \
	   key_press/close_game.c \
	   collectible_floating_motion/collectible_floating_motion.c

OBJS_DIR = objs
OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

all: $(NAME)

clean:
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(LIBPRINTF_DIR)
	make fclean -C $(LIBGNL_DIR)
	make clean -C $(LIBMLX_DIR)
	make fclean -C $(LIBDLL_DIR)
	$(RM) $(RMFLAGS) $(OBJS_DIR)

fclean: clean
	$(RM) $(RMFLAGS) $(NAME)

re:
	make fclean
	make all

$(NAME): $(OBJS)
	make all -C $(LIBFT_DIR)
	make all -C $(LIBPRINTF_DIR)
	make all -C $(LIBGNL_DIR)
	make all -C $(LIBMLX_DIR)
	make all -C $(LIBDLL_DIR)
	$(CC) $(CFLAGS) -L$(LIBFT_DIR) -l$(LIBFT_NAME) -L$(LIBPRINTF_DIR) -l$(LIBPRINTF_NAME) -L$(LIBGNL_DIR) -l$(LIBGNL_NAME) -L$(LIBMLX_DIR) -l$(LIBMLX_NAME) $(MLXFLAGS) -L$(LIBDLL_DIR) -l$(LIBDLL_NAME) -o $@ $^

$(OBJS): $(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	mkdir -p $(OBJS_DIR)/{map_utils,parse_map,init_game_data,init_game_data/map_labeling,print_map,key_press,collectible_floating_motion}
	$(CC) $(CFLAGS) -c $< -o $@ -I$(HEADER_DIR)

.PHONY : all clean fclean re
