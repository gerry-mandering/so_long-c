/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_char_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 02:55:30 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/17 02:55:44 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	free_char_map(char **map, const t_idx map_size)
{
	int	i;

	i = 0;
	while (i < map_size.row)
		ft_free(map[i++]);
	ft_free(map);
}
