/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:49:31 by minseok2          #+#    #+#             */
/*   Updated: 2022/11/13 21:50:51 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

//FIX!!!!!!!!!!!!!
void	print_map(char **arr_map, t_coord *map_size)
{
	int	i;

	i = 0;
	while (i < map_size->col)
	{
		ft_printf("%s\n", arr_map[i]);
		i++;
	}
}
