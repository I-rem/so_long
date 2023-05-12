/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikayacio <ikayacio@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:57:59 by ikayacio          #+#    #+#             */
/*   Updated: 2023/05/12 14:15:22 by ikayacio         ###   ########.fr       */
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
# define COIN "textures/chest_golden_open_full.xpm"
# define EXIT "textures/Floor_ladder.xpm"
# define PLAYER "textures/npc_paladin.xpm"
# define FLOOR "textures/Edge_single.xpm"
# define WALL "textures/Wall_front.xpm"
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2

typedef struct s_img
{
	void	*img_ptr;
}	t_img;
struct s_map_data
{
	int		rows;
	int		collumns;
	int		c_count;
	int		e_count;
	int		p_count;
	int		p_position_x;
	int		p_position_y;
	char	*map[100];
};
typedef struct s_data
{
	struct s_map_data	map_data;
	struct s_map_data	map_data2;
	void				*mlx_ptr;
	void				*win_ptr;
	int					move_count;
	t_img				coin;
	t_img				player;
	t_img				floor;
	t_img				wall;
	t_img				exit;
}	t_data;
int		ft_strlen(char *s);
void	arg_check(int argc, char *argv[]);
void	open_window(t_data *data);
int		handle_no_event(t_data *data);
int		handle_input(int keysym, t_data *data);
void	map_check(char *mapfile, t_data *data);
void	rectangle_check(t_data *data);
void	rectangle_check2(t_data *data);
void	border_check(t_data *data);
void	invalid_map(t_data *data);
int		ft_printf(const char *format, ...);
void	map_init(t_data *data);
void	char_check(t_data *data);
void	char_count(t_data *data);
void	img_init(t_data *data);
void	render_map(t_data *data);
void	move(t_data *data, int x, int y);
void	check_move(t_data *data, int keycode);
int		close_program(t_data *data);
void	flood_fill(t_data *data, int x, int y);
#endif
