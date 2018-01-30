/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroguszk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 16:12:44 by jroguszk          #+#    #+#             */
/*   Updated: 2018/01/26 15:06:46 by jroguszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FDF_H
# define __FDF_H
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "includes/libft/includes/libft.h"
# include "minilibx/mlx.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>

# define WIDTH 1920
# define HEIGHT 1080
# define ROTATE 0.098174
# define POS(i) (i < 0 ? -i : i)
# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 124
# define RIGHT 123
# define ZDOWN 13
# define ZUP 1
# define ZOOMA 6
# define ZOOMB 7
# define RED 15
# define GREEN 5
# define BLUE 11
# define PURPLE 35
# define BLACK 31
# define MOVE_UP 91
# define MOVE_DOWN 84
# define MOVE_RIGHT 88
# define MOVE_LEFT 86

typedef	struct	s_env
{
	int		bits;
	int		sizeline;
	int		endian;
	int		x;
	int		y;
	int		z;
	int		**grid;
	int		**grid2;
	int		**grid3;
	int		*addr;
	int		i;
	int		j;
	double	tmpx;
	double	tmpy;
	double	x_2;
	double	y_2;
	double	z_2;
	int		centre;
	void	*mlx;
	void	*win;
	void	*img;

}				t_env;

typedef	struct	s_var
{
	int		fd;
	int		ret;
	int		size;
	char	**tmp;
	char	*line;
}				t_var;

typedef	struct	s_transform
{
	int		x;
	int		y;
	int		z;
	int		colour;
	int		background;
	int		move_horizontal;
	int		move_vertical;
	double	zoom;
	double	r_x;
	double	r_y;
	double	r_z;
}				t_transform;

int				get_size(char *argv);
void			store_array(char *line, t_env *e);
int				set_up(t_env *e, char *argv);
int				key_hook(int keycode, t_env *e);
void			draw(t_env *e, t_transform *r);
int				main(int argc, char **argv);
int				ft_round(double i);
void			ft_clear(t_env *e, t_transform *r);
void			draw_horizontal(double x1, double y1, t_env *e, t_transform *r);
void			draw_vertical(double x1, double y1, t_env *e, t_transform *r);
void			ft_putpixel(double x, double y, t_env *e, t_transform *r);
void			ft_swap_double(double *x, double *x1, double *y, double *y1);
void			rotate(t_env *e, t_transform *r);
int				zoom(int keycode, t_transform *r);
int				colour(int keycode, t_transform *r);
int				move(int keycode, t_transform *r);

#endif
