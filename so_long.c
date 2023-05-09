/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikayacio <ikayacio@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:40:04 by ikayacio          #+#    #+#             */
/*   Updated: 2023/05/09 15:26:40 by ikayacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	arg_check(int argc, char *argv[])
{
	int	len;

	if (argc == 2)
	{
		len = ft_strlen(argv[1]);
		len--;
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

void	map_check(char *mapfile)
{
	int		fd;
	char	*path;
	char	*map[100];
	int		i;

	path = ft_strjoin("maps/", mapfile);
	fd = open(path, O_RDONLY);
	free(path);
	if (fd < 0)
	{
		close(fd);
		write(2, "Error\nInvalid file", 18);
		exit(EXIT_FAILURE);
	}
	i = 0;
	map[i] = get_next_line(fd);
	while (map[i])
	{
		i++;
		map[i] = get_next_line(fd);
	}
}

int	main(int argc, char *argv[])
{
	t_data	data;

	arg_check(argc, argv);
	map_check(argv[1]);
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (2);
	data.win_ptr = open_window(data.mlx_ptr);
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (2);
	}
	mlx_key_hook(data.win_ptr, &handle_input, &data);
	mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
	mlx_loop(data.mlx_ptr);
}
