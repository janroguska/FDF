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
	static	t_transform	r;

	ft_clear(e);
	draw(e, &r);
	if (keycode == 53)
		exit(0);
	else if (keycode == 123)
		r.r_x += 0.098174;
	else if (keycode == 124)
		r.r_y += 0.098174;
	else if (keycode == 126)
		r.r_z += 0.098174;
	return (0);
}

int		ft_round(double i)
{
	return (i < 0 ? i - 0.5 : i + 0.5);
}

void	ft_clear(t_env *e)
{
	int		i;
	int		j;

	i = 0;
	j = HEIGHT * WIDTH;
	while (i < j)
	{
		e->addr[i] = 0x000000;
		i++;
	}
}

void	drawline1(t_env *e, t_transform *t)
{

}

void	draw(t_env *e, t_transform *r)
{
	e->i = 0;
	e->j = 0;
	e->centre = (((WIDTH * HEIGHT) / 2) + WIDTH) / 2;
	while (e->i < e->y)
	{
		e->j = 0;
		r->y = 4 * e->i;
		while (e->j < e->x)
		{
			r->x = 4 * e->j;
			r->z = 1 * e->grid[e->i][e->j];
			e->x_2 = ft_round((r->y * cos(r->r_x)) - (r->z * sin(r->r_x))) * WIDTH
			 + (ft_round((r->y * sin(r->r_x)) + (r->z * cos(r->r_x)))) + r->x;
			e->y_2 = ft_round((r->z * cos(r->r_y)) - (r->x * sin(r->r_y)))
			 + (ft_round((r->z * sin(r->r_y)) + (r->x * cos(r->r_y)))) + (r->y * WIDTH);
			e->z_2 = ft_round((r->x * cos(r->r_z)) - (r->y * sin(r->r_z)))
			 + (ft_round(((r->x * sin(r->r_z)) + (r->y * cos(r->r_z)))) * WIDTH) + r->z;
			e->addr[ft_round(e->x_2 + e->y_2 + e->z_2 + e->centre)] = 0xFFFFFF;
			e->j++;
		}
		e->i++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

int		main(int argc, char **argv)
{
	t_env		e;
	t_transform	r;

	if (argc != 2)
		return (0);
	set_up(&e, argv[1]);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIDTH, HEIGHT, argv[1]);
	e.img = mlx_new_image(e.mlx, WIDTH, HEIGHT);
	e.addr = (int*)mlx_get_data_addr(e.img, &e.bits, &e.sizeline, &e.endian);
	draw(&e, &r);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}