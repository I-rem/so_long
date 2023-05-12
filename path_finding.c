/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikayacio <ikayacio@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:37:06 by ikayacio          #+#    #+#             */
/*   Updated: 2023/05/12 17:13:00 by ikayacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill(t_data *data, int x, int y)
{
	if ((*data).map_data2.map[x][y] == '1' || x < 0 ||
		y < 0 || (*data).map_data2.map[x][y] == 'x')
		return ;
	(*data).map_data2.map[x][y] = 'x';
	fill (data, x, y - 1);
	fill (data, x, y + 1);
	fill (data, x - 1, y);
	fill (data, x + 1, y);
}

void	flood_fill(t_data *data, int x, int y)
{
	int	i;
	int	j;

	fill(data, y, x);
	i = 0;
	j = 0;
	while ((*data).map_data2.map[i])
	{
		while ((*data).map_data2.map[i][j] != '\n')
		{
			if ((*data).map_data2.map[i][j] == 'E' ||
					(*data).map_data2.map[i][j] == 'C')
				invalid_map(data);
			j++;
		}
		j = 0;
		i++;
	}
}
