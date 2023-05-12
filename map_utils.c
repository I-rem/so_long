/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikayacio <ikayacio@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:21:18 by ikayacio          #+#    #+#             */
/*   Updated: 2023/05/11 13:33:16 by ikayacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	rectangle_check(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map_data.map[0][i])
		i++;
	data->map_data.collumns = i;
	while (data->map_data.map[j])
		j++;
	data->map_data.rows = j;
	i = 0;
	j = 0;
	while (data->map_data.map[i])
	{
		while (data->map_data.map[i][j])
			j++;
		if (j != data->map_data.collumns)
			invalid_map(data);
		j = 0;
		i++;
	}
	rectangle_check2(data);
}

void	rectangle_check2(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map_data.map[i][j])
	{
		while (data->map_data.map[i])
			i++;
		if (i != data->map_data.rows)
			invalid_map(data);
		i = 0;
		j++;
	}
	border_check(data);
}

void	border_check(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map_data.map[i])
	{
		j = 0;
		while (data->map_data.map[i][j] != '\n')
		{
			if ((i == 0 || j == 0 || i == data->map_data.rows
					|| j == data->map_data.collumns - 1)
				&& data->map_data.map[i][j] != '1')
				invalid_map(data);
			j++;
		}
		i++;
	}
	map_init(data);
}

void	char_check(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map_data.map[++i])
	{
		j = -1;
		while (data->map_data.map[i][++j] != '\n')
		{
			if (data->map_data.map[i][j] == 'C')
				data->map_data.c_count++;
			else if (data->map_data.map[i][j] == 'E')
				data->map_data.e_count++;
			else if (data->map_data.map[i][j] == 'P')
			{
				data->map_data.p_count++;
				data->map_data.p_position_x = j;
				data->map_data.p_position_y = i;
			}
			else if (data->map_data.map[i][j] != '1'
					&& data->map_data.map[i][j] != '0')
				invalid_map(data);
		}
	}
	char_count(data);
}

void	char_count(t_data *data)
{
	if (data->map_data.p_count != 1 || data->map_data.e_count != 1
		|| data->map_data.c_count < 1)
		invalid_map(data);
}
