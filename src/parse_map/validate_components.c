/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_components.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 00:40:12 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/18 19:38:19 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	is_components(char c)
{
	if (c == C_ROAD || c == C_WALL || c == C_COLLECTIBLE || \
			c == C_EXIT || c == C_PLAYER)
		return (1);
	else
		return (0);
}

static void	lift_components_flag(t_components *components_flag, char c)
{
	if (c == C_WALL)
		components_flag->wall |= EXIST;
	else if (c == C_COLLECTIBLE)
		components_flag->collectible |= EXIST;
	else if (c == C_EXIT)
	{
		if (components_flag->exit == EXIST)
			ft_exit("Error\nduplicate exits", STDERR_FILENO, EXIT_FAILURE);
		components_flag->exit |= EXIST;
	}
	else if (c == C_PLAYER)
	{
		if (components_flag->player == EXIST)
			ft_exit("Error\nduplicate players", STDERR_FILENO, EXIT_FAILURE);
		components_flag->player |= EXIST;
	}
}

static void	check_all_components_exist(t_components *components_flag)
{
	if (components_flag->wall == NOT_EXIST)
		ft_exit("Error\nno wall in map", STDERR_FILENO, EXIT_FAILURE);
	else if (components_flag->collectible == NOT_EXIST)
		ft_exit("Error\nno collectible in map", STDERR_FILENO, EXIT_FAILURE);
	else if (components_flag->exit == NOT_EXIST)
		ft_exit("Error\nno exit in map", STDERR_FILENO, EXIT_FAILURE);
	else if (components_flag->player == NOT_EXIST)
		ft_exit("Error\nno player in map", STDERR_FILENO, EXIT_FAILURE);
}

void	validate_components(char **map, const t_idx map_size)
{
	t_idx			idx;
	t_components	components_flag;

	ft_memset(&idx, 0, sizeof(t_idx));
	ft_memset(&components_flag, NOT_EXIST, sizeof(t_components));
	while (idx.row < map_size.row)
	{
		idx.col = 0;
		while (idx.col < map_size.col)
		{
			if (!is_components(map[idx.row][idx.col]))
				ft_exit("Error\nwrong components", STDERR_FILENO, EXIT_FAILURE);
			lift_components_flag(&components_flag, map[idx.row][idx.col]);
			idx.col++;
		}
		idx.row++;
	}
	check_all_components_exist(&components_flag);
}
