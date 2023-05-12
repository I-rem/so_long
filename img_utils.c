/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikayacio <ikayacio@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:05:53 by ikayacio          #+#    #+#             */
/*   Updated: 2023/05/12 11:53:47 by ikayacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_init(t_data *data)
{
	int	w;
	int	h;

	w = 16;
	h = 16;
	data->player.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, PLAYER, &w, &h);
	data->coin.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, COIN, &w, &h);
	data->exit.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, EXIT, &w, &h);
	data->floor.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, FLOOR, &w, &h);
	data->wall.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, WALL, &w, &h);
	render_map(data);
	mlx_key_hook(data->win_ptr, &handle_input, data);
	mlx_loop_hook(data->mlx_ptr, &handle_no_event, data);
	mlx_loop(data->mlx_ptr);
}

void	check_move(t_data *data, int keycode)
{
	int	x;
	int	y;

	x = data -> map_data.p_position_x;
	y = data -> map_data.p_position_y;
	if (keycode == W && (*data).map_data.map[y - 1][x] != '1')
		move(data, x, y - 1);
	if (keycode == S && (*data).map_data.map[y + 1][x] != '1')
		move(data, x, y + 1);
	if (keycode == A && (*data).map_data.map[y][x - 1] != '1')
		move(data, x - 1, y);
	if (keycode == D && (*data).map_data.map[y][x + 1] != '1')
		move(data, x + 1, y);
}

void	move(t_data *data, int x, int y)
{
	(*data).move_count++;
	ft_printf("Movement count: %d\n", (*data).move_count);
	(*data).map_data.p_position_x = x;
	(*data).map_data.p_position_y = y;
	if ((*data).map_data.map[y][x] == 'C')
	{
		(*data).map_data.map[y][x] = '0';
		(*data).map_data.c_count--;
	}
	else if ((*data).map_data.map[y][x] == 'E')
	{
		if ((*data).map_data.c_count != 0)
			ft_printf("You have more treasure to collect!\n");
		else
		{
			ft_printf("Game Over Good Job!\n");
			close_program(data);
		}
	}
}
