/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikayacio <ikayacio@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:40:04 by ikayacio          #+#    #+#             */
/*   Updated: 2023/05/05 13:30:44 by ikayacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Need to take a map description file endsing with the .ber extension
// How to includeminilibx wşthout norminette causing problems?

#include "so_long.h"

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	len--;
	return (len);
}

void	arg_check(int argc, char *argv[])
{
	int	len;

	if (argc == 2)
	{
		len = ft_strlen(argv[1]);
		if (argv[1][len] == 'r')
		{
			len--;
			if (argv[1][len] == 'e')
			{
				len--;
				{
					if (argv[1][len] == 'b')
						len--;
					{
						if (argv[1][len] == '.')
							return ;
					}
				}
			}
		}
	}
	write(2, "Wrong argument", 14);
	exit(EXIT_FAILURE);
}

void	*open_window(void *mlx_ptr)
{
	return (mlx_new_window(mlx_ptr, 500, 500, "My Game"));
}

int	main(int argc, char *argv[])
{
	void	*mlx_ptr;
	void	*win_ptr;

	arg_check(argc, argv);
	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return (MLX_ERROR);
	win_ptr = open_window(mlx_ptr);
	if (win_ptr == NULL)
		return (MLX_ERROR);
	mlx_loop(mlx_ptr);
	// mlx_destroy_window(mlx_ptr, win_ptr);
	// mlx_destroy_display(mlx_ptr);
	// free(mlx_ptr);
}
