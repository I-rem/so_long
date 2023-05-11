/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikayacio <ikayacio@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:12:06 by ikayacio          #+#    #+#             */
/*   Updated: 2023/05/11 12:58:40 by ikayacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void	render_map(t_data *data);
int	handle_no_event(t_data *data)
{
	(void)data;
	//render_map(data);
	//mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player.img_ptr, 0, 0);
	return (0);
}

void	render_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	
	while (data->map_data.map[i])
	{
		j = 0;
		while ((*data).map_data.map[i][j])
		{
			
			if ((*data).map_data.map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->coin.img_ptr, i*16, j*16);
			else if ((*data).map_data.map[i][j] == 'E')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->exit.img_ptr, i*16, j*16);
			else if ((*data).map_data.map[i][j] == 'P')
			{
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor.img_ptr, i*16, j*16);
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player.img_ptr, i*16, j*16);
			}
			else if ((*data).map_data.map[i][j] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->wall.img_ptr, i*16, j*16);
			else if ((*data).map_data.map[i][j] == '0')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor.img_ptr, i*16, j*16);
			j++;
		}
		i++;
	}
}

int	handle_input(int keycode, t_data *data)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit(EXIT_SUCCESS);
	}
	if (keycode == W)
		render_map(data);
	return (0);
}

int	close_program(void)
{
	// Destrıy images, free memory
	//free(data.mlx_ptr);
	exit(0);
}

void	*open_window(void *mlx)
{
	void	*win_ptr;

	win_ptr = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "My Game");
	mlx_hook(win_ptr, 17, 0, close_program, 0);
	return (win_ptr);
}
