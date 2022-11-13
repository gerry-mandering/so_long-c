/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_components.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:36:27 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/13 21:40:20 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	is_component(char c)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P')
		return (1);
	else
		return (0);
}

static void	check_components_duplicate(t_components *components, char c)
{
	if (c == '1')
		components->wall |= EXIST;
	else if (c == 'C')
		components->collectibles |= EXIST;
	else if (c == 'E')
	{
		if (components->exit == EXIST)
			ft_exit("duplicate exits\nError", STDERR_FILENO, EXIT_FAILURE);
		components->exit = EXIST;
	}
	else if (c == 'P')
	{
		if (components->starting_position == EXIST)
			ft_exit("duplicate starting_position\nError", \
					STDERR_FILENO, EXIT_FAILURE);
		components->starting_position = EXIST;
	}
}

static void	check_components_exist(t_components *components)
{
	if (components->wall == NOT_EXIST)
		ft_exit("wall doesn't exist\nError", STDERR_FILENO, EXIT_FAILURE);
	else if (components->collectibles == NOT_EXIST)
		ft_exit("collectibles doesn't exist\nError", \
				STDERR_FILENO, EXIT_FAILURE);
	else if (components->exit == NOT_EXIST)
		ft_exit("exit doesn't exist\nError", STDERR_FILENO, EXIT_FAILURE);
	else if (components->starting_position == NOT_EXIST)
		ft_exit("starting_position doesn't exist\nError", \
				STDERR_FILENO, EXIT_FAILURE);
}

void	validate_components(t_list *list_map)
{
	int				i;
	t_components	components;
	t_node			*current_node;

	ft_memset(&components, NOT_EXIST, sizeof(t_components));
	current_node = list_map->head->next;
	while (current_node->next != NULL)
	{
		i = 0;
		while ((current_node->line)[i])
		{
			if (!is_component((current_node->line)[i]))
				ft_exit("wrong component\nError", STDERR_FILENO, EXIT_FAILURE);
			check_components_duplicate(&components, (current_node->line)[i]);
			i++;
		}
		current_node = current_node->next;
	}
	check_components_exist(&components);
}
