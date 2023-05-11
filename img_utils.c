/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikayacio <ikayacio@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:05:53 by ikayacio          #+#    #+#             */
/*   Updated: 2023/05/11 12:28:26 by ikayacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_init(t_data *data)
{
	int	w;
	int	h;

	w = 16;
	h = 16;
	printf("%s", data->map_data.map[0]);
	data->player.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, PLAYER, &w, &h);
	data->coin.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, COIN, &w, &h);
	data->exit.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, EXIT, &w, &h);
	data->floor.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, FLOOR, &w, &h);
	data->wall.img_ptr = mlx_xpm_file_to_image(data->mlx_ptr, WALL, &w, &h);
	mlx_key_hook(data->win_ptr, &handle_input, data);
	mlx_loop_hook(data->mlx_ptr, &handle_no_event, data);
	mlx_loop(data->mlx_ptr);
}
