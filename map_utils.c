/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikayacio <ikayacio@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:21:18 by ikayacio          #+#    #+#             */
/*   Updated: 2023/05/10 14:21:18 by ikayacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	rectangle_check(struct s_map_data map_data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map_data.map[0][i])
		i++;
	map_data.collumns = i;
	while (map_data.map[j])
		j++;
	map_data.rows = j;
	i = 0;
	j = 0;
	while (map_data.map[i])
	{
		while (map_data.map[i][j])
			j++;
		if (j != map_data.collumns)
			invalid_map(map_data);
		j = 0;
		i++;
	}
	rectangle_check2(map_data);
}

void	rectangle_check2(struct s_map_data map_data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map_data.map[i][j])
	{
		while (map_data.map[i])
			i++;
		if (i != map_data.rows)
			invalid_map(map_data);
		i = 0;
		j++;
	}
	border_check(map_data);
}

void	border_check(struct s_map_data map_data)
{
	int	i;
	int	j;

	i = 0;
	while (map_data.map[i])
	{
		j = 0;
		while (map_data.map[i][j] != '\n')
		{
			if ((i == 0 || j == 0 || i == map_data.rows
					|| j == map_data.collumns - 1) && map_data.map[i][j] != '1')
				invalid_map(map_data);
			j++;
		}
		i++;
	}
	map_init(map_data);
}

void	char_check(struct s_map_data map_data)
{
	int	i;
	int	j;

	i = -1;
	while (map_data.map[++i])
	{
		j = 0;
		while (map_data.map[i][j] != '\n')
		{
			if (map_data.map[i][j] == 'C')
				map_data.c_count++;
			else if (map_data.map[i][j] == 'E')
				map_data.e_count++;
			else if (map_data.map[i][j] == 'P')
			{
				map_data.p_count++;
				map_data.p_position_x = j;
				map_data.p_position_y = i;
			}
			else if (map_data.map[i][j] != '1' && map_data.map[i][j] != '0')
				invalid_map(map_data);
			j++;
		}
	}
	char_count(map_data);
}

void	char_count(struct s_map_data map_data)
{
	if (map_data.p_count != 1 || map_data.e_count != 1 || map_data.c_count < 1)
		invalid_map(map_data);
}
