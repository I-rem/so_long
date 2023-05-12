/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikayacio <ikayacio@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:40:04 by ikayacio          #+#    #+#             */
/*   Updated: 2023/05/12 16:38:17 by ikayacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_init(t_data *data)
{
	(*data).move_count = 0;
	data->map_data.c_count = 0;
	data->map_data.e_count = 0;
	data->map_data.p_count = 0;
	char_check(data);
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
	write(2, "Error\nWrong argument", 20);
	exit(EXIT_FAILURE);
}

void	map_check(char *mapfile, t_data *data)
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
	data->map_data.map[i] = get_next_line(fd);
	while (data->map_data.map[i])
	{
		data->map_data2.map[i] = ft_strdup(data->map_data.map[i]);
		i++;
		data->map_data.map[i] = get_next_line(fd);
	}
	data->map_data2.map[i] = NULL;
	close(fd);
	rectangle_check (data);
}

void	invalid_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map_data.map[i])
	{
		free(data->map_data.map[i]);
		i++;
	}
	i = 0;
	while (data->map_data2.map[i])
	{
		free(data->map_data.map[i]);
		i++;
	}
	write(2, "Error\nInvalid map", 17);
	exit (EXIT_FAILURE);
}

int	main(int argc, char *argv[])
{
	t_data				data;

	arg_check(argc, argv);
	map_check(argv[1], &data);
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (2);
	open_window(&data);
	if (data.win_ptr == NULL)
	{
		free(data.mlx_ptr);
		free(data.win_ptr);
		return (2);
	}
	img_init(&data);
	return (0);
}
