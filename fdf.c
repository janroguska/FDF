/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroguszk <jroguszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 10:10:47 by jroguszk          #+#    #+#             */
/*   Updated: 2018/01/08 17:54:25 by jroguszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		get_size(char *argv)
{
	t_var	b;
	int		i;

	b.fd = open(argv, O_RDONLY);
	if (b.fd == -1)
		return (0);
	while ((b.ret = get_next_line(b.fd, &b.line)) > 0)
	{
		if (b.ret == -1)
			return (0);
		free(b.line);
		i++;
	}
	free(b.line);
	if (close(b.fd) == -1)
		return (0);
	return (i);
}

void	store_array(char *line, t_env *e)
{
	t_var	b;
	char	*join;

	e->x = 0;
	b.tmp = ft_strsplit(line, ' ');
	e->grid[e->y] = (int*)malloc(sizeof(int*) * (sizeof(b.tmp) + 1));
	free(line);
	while (b.tmp[e->x])
	{
		e->grid[e->y][e->x] = ft_atoi(b.tmp[e->x]);
		free(b.tmp[e->x]);
		e->x++;
	}
	free(b.tmp);
}

int		set_up(t_env *e, char *argv)
{
	t_var	b;

	e->y = 0;
	b.fd = open(argv, O_RDONLY);
	if (b.fd == -1)
		return (0);
	if ((b.size = get_size(argv)) <= 0)
		return (0);
	if ((e->grid = (int**)malloc(sizeof(int*) * (b.size + 1))) == NULL)
		return (0);
	while ((b.ret = get_next_line(b.fd, &b.line)) > 0)
	{
		if (b.ret == -1)
			return (0);
		store_array(b.line, e);
		e->y++;
	}
	e->grid[e->y] = NULL;
	free(b.line);
	close(b.fd);
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

int		ft_round(double i)
{
	return (i < 0 ? i - 0.5 : i + 0.5);
}

void	draw(t_env *e)
{
	int		i;
	int		j;
	int		x;
	int		y;
	int		z;
	double	x_2;
	double	y_2;
	double	z_2;
	int centre;

	i = 0;
	j = 0;
	e->i_cos = cos(0.523599);
	e->i_sin = sin(0.523599);
	centre = (((WIDTH * HEIGHT) / 2) + WIDTH) / 2;
	while (i < e->y)
	{
		j = 0;
		y = 8 * i;	
		while (j < e->x)
		{
			x = 8 * j;
			z = 8 * e->grid[i][j];
			x_2 = ft_round(((x * e->i_cos) - (y * e->i_sin)));
			y_2 = (ft_round(((x * e->i_sin) + (y * e->i_cos))) * WIDTH);
//			e->addr[ft_round((y_2 + x_2 + centre))] = 0xFFFFFF;
			e->addr[ft_round((z * e->i_cos) - (x * e->i_sin) + (z * e->i_sin) + (x * e->i_cos) + (y * WIDTH) + centre)] = 0xFFFFFF;
			j++;
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	t_env	e;

	if (argc != 2)
		return (0);
	set_up(&e, argv[1]);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIDTH, HEIGHT, argv[1]);
	e.img = mlx_new_image(e.mlx, WIDTH, HEIGHT);
	e.addr = (int*)mlx_get_data_addr(e.img, &e.bits, &e.sizeline, &e.endian);
	draw(&e);
	mlx_put_image_to_window(e.mlx, e.win, e.img, 0, 0);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}