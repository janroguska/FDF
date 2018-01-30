/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroguszk <jroguszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 10:10:47 by jroguszk          #+#    #+#             */
/*   Updated: 2018/01/30 15:23:11 by jroguszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_round(double i)
{
	return (i < 0 ? i - 0.5 : i + 0.5);
}

void	ft_swap_double(double *x, double *x1, double *y, double *y1)
{
	double		temp;

	temp = *x;
	*x = *x1;
	*x1 = temp;
	temp = *y;
	*y = *y1;
	*y1 = temp;
}

int		main(int argc, char **argv)
{
	t_env		e;
	t_transform	r;

	r.zoom = 0;
	r.colour = 0xFFFFFF;
	if (argc != 2)
		return (0);
	set_up(&e, argv[1]);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIDTH, HEIGHT, argv[1]);
	e.img = mlx_new_image(e.mlx, WIDTH, HEIGHT);
	e.addr = (int*)mlx_get_data_addr(e.img, &e.bits, &e.sizeline, &e.endian);
	draw(&e, &r);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_put_image_to_window(e.mlx, e.win, e.img, 0, 0);
	mlx_loop(e.mlx);
	return (0);
}
