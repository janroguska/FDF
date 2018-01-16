/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroguszk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 16:12:44 by jroguszk          #+#    #+#             */
/*   Updated: 2018/01/15 16:12:45 by jroguszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FDF_H
# define __FDF_H
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "./includes/libft/includes/libft.h"

# include "includes/libft/includes/libft.h"
# include "includes/get_next_line.h"
# include "minilibx/mlx.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

# define WIDTH 800
# define HEIGHT 600

typedef	struct s_env
{
	int		bits;
	int		sizeline;
	int		endian;
	int		x;
	int		y;
	int		z;
	double	i_cos;
	double	i_sin;
	int		**grid;
	void	*mlx;
	void	*win;
	void	*img;
	int		*addr;
}				t_env;

typedef	struct s_var
{
	int		fd;
	int		ret;
	int		size;
	char	**tmp;
	char	*line;
}				t_var;

int		get_size(char *argv);
void	store_array(char *line, t_env *e);
int		set_up(t_env *e, char *argv);
int		key_hook(int keycode, t_env *e);
void	draw(t_env *e);
int		main(int argc, char **argv);
int		ft_round(double i);

#endif
