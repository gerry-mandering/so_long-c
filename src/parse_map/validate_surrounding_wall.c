/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_surrounding_wall.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:41:04 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/13 21:41:45 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	is_all_wall(char *line)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(line);
	while (i < len)
	{
		if (line[i] != '1')
			ft_exit("wrong map\nError", STDERR_FILENO, EXIT_FAILURE);
		i++;
	}
}

static void	is_both_ends_wall(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (line[0] != '1' || line[len - 1] != '1')
		ft_exit("wrong map\nError", STDERR_FILENO, EXIT_FAILURE);
}

void	validate_surrounding_wall(t_list *list_map)
{
	t_node	*current_node;
	t_node	*first_node;
	t_node	*last_node;

	current_node = list_map->head->next;
	first_node = current_node;
	last_node = list_map->tail->prev;
	while (current_node->next != NULL)
	{
		if (current_node == first_node || current_node == last_node)
			is_all_wall(current_node->line);
		else
			is_both_ends_wall(current_node->line);
		current_node = current_node->next;
	}
}
