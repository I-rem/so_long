/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikayacio <ikayacio@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:57:59 by ikayacio          #+#    #+#             */
/*   Updated: 2023/05/10 13:02:10 by ikayacio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "mlx/mlx.h"
# include "get_next_line.h"
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdarg.h>
# define WINDOW_WIDTH 500
# define WINDOW_HEIGHT 500
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;
struct s_map_data
{
	int		rows;
	int		collumns;
	int		c_count;
	char	*map[100];
};
int		ft_strlen(char *s);
void	arg_check(int argc, char *argv[]);
void	*open_window(void *mlx);
int		handle_no_event(void *data);
int		handle_input(int keysym, t_data *data);
void	map_check(char *mapfile);
void	rectangle_check(struct s_map_data map_data);
void	rectangle_check2(struct s_map_data map_data);
void	border_check(struct s_map_data map_data);
void	invalid_map(struct s_map_data map_data);
int		ft_printf(const char *format, ...);
#endif
