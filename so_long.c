/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikayacio <ikayacio@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:40:04 by ikayacio          #+#    #+#             */
/*   Updated: 2023/05/10 18:11:37 by ikayacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_init(struct s_map_data map_data)
{
	map_data.c_count = 0;
	map_data.e_count = 0;
	map_data.p_count = 0;
	char_check(map_data);
}

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

void	map_check(char *mapfile, struct	s_map_data map_data)
{
	int					fd;
	char				*path;
	int					i;

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
	map_data.map[i] = get_next_line(fd);
	while (map_data.map[i])
	{
		i++;
		map_data.map[i] = get_next_line(fd);
	}
	close(fd);
	rectangle_check (map_data);
}

void	invalid_map(struct s_map_data map_data)
{
	int	i;

	i = 0;
	while (map_data.map[i])
	{
		free(map_data.map[i]);
		i++;
	}
	write(2, "Error\nInvalid map", 17);
	exit (EXIT_FAILURE);
}

int	main(int argc, char *argv[])
{
	t_data				data;

	arg_check(argc, argv);
	map_check(argv[1], data.map_data);
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (2);
	data.win_ptr = open_window(data.mlx_ptr);
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (2);
	}
	void    *img;
    int w = 10;
    int h = 10;
    img = mlx_xpm_file_to_image(data.mlx_ptr, "texture/hero_basic.xpm", &w, &h);
    mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img, 0, 0);
	write(2, "test", 4);
	mlx_key_hook(data.win_ptr, &handle_input, &data);
	mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
	mlx_loop(data.mlx_ptr);
}
