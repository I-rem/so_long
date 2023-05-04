/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikayacio <ikayacio@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:40:04 by ikayacio          #+#    #+#             */
/*   Updated: 2023/05/04 16:40:06 by ikayacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Need to take a map description file endsing with the .ber extension
// Check how you should be including the minilibx library because norminette might cause problems
#include "minilibx/mlx.h"

int main()
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 500, 500, "My Game");
	mlx_loop(mlx_ptr);
}
