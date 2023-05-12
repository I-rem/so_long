/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikayacio <ikayacio@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:12:06 by ikayacio          #+#    #+#             */
/*   Updated: 2023/05/12 12:10:12 by ikayacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_no_event(t_data *data)
{
	(void)data;
	return (0);
}

void	render_map(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map_data.map[++i])
	{
		j = -1;
		while ((*data).map_data.map[i][++j] != '\n')
		{			
			mlx_put_image_to_window(data -> mlx_ptr, data -> win_ptr,
				data -> floor.img_ptr, j * 16, i * 16);
			if ((*data).map_data.map[i][j] == 'C')
				mlx_put_image_to_window(data -> mlx_ptr, data -> win_ptr,
					data -> coin.img_ptr, j * 16, i * 16);
			else if ((*data).map_data.map[i][j] == 'E')
				mlx_put_image_to_window(data -> mlx_ptr, data -> win_ptr,
					data -> exit.img_ptr, j * 16, i * 16);
			else if ((*data).map_data.map[i][j] == '1')
				mlx_put_image_to_window(data -> mlx_ptr, data -> win_ptr,
					data -> wall.img_ptr, j * 16, i * 16);
		}
	}
	mlx_put_image_to_window(data -> mlx_ptr, data -> win_ptr,
		data -> player.img_ptr, data -> map_data.p_position_x * 16,
		data -> map_data.p_position_y * 16);
}

int	handle_input(int keycode, t_data *data)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit(EXIT_SUCCESS);
	}
	if (keycode == W || keycode == A
		|| keycode == S || keycode == D)
	{
		check_move(data, keycode);
		render_map(data);
	}
	return (0);
}

// Destroy images, free memory
int	close_program(t_data *data)
{
	free(data->mlx_ptr);
	exit(0);
}

void	open_window(t_data *data)
{
	data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH,
			WINDOW_HEIGHT, "My Game");
	mlx_hook(data->win_ptr, 17, 0, close_program, data);
}
