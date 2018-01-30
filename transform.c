/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroguszk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 15:21:34 by jroguszk          #+#    #+#             */
/*   Updated: 2018/01/26 15:21:36 by jroguszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate(t_env *e, t_transform *r)
{
	r->y = e->i * (10 + r->zoom);
	r->x = e->j * (10 + r->zoom);
	r->z = e->grid[e->i][e->j] * ((10 + r->zoom) / 4);
	e->y_2 = ft_round((r->y * cos(r->r_x)) - (r->z * sin(r->r_x)));
	e->z_2 = ft_round((r->y * sin(r->r_x)) + (r->z * cos(r->r_x)));
	e->x_2 = r->x;
	r->x = e->x_2;
	r->y = e->y_2;
	r->z = e->z_2;
	e->z_2 = ft_round((r->z * cos(r->r_y)) - (r->x * sin(r->r_y)));
	e->x_2 = ft_round((r->z * sin(r->r_y)) + (r->x * cos(r->r_y)));
	e->y_2 = r->y;
	r->x = e->x_2;
	r->y = e->y_2;
	r->z = e->z_2;
	e->x_2 = ft_round((r->x * cos(r->r_z)) - (r->y * sin(r->r_z)));
	e->y_2 = ft_round(((r->x * sin(r->r_z)) + (r->y * cos(r->r_z))));
	e->z_2 = r->z;
	e->grid2[e->i][e->j] = e->x_2;
	e->grid3[e->i][e->j] = e->y_2;
}

int		colour(int keycode, t_transform *r)
{
	if (r->colour == 0)
		r->colour = 0xFFFFFF;
	else if (keycode == RED)
		r->colour = 0xFF0000;
	else if (keycode == GREEN)
		r->colour = 0x00FF00;
	else if (keycode == BLUE)
		r->colour = 0x00FFFF;
	else if (keycode == PURPLE)
		r->background = 0xB833FF;
	else if (keycode == BLACK)
		r->background = 0x000000;
	return (0);
}

int		zoom(int keycode, t_transform *r)
{
	if (keycode == ZOOMA)
		r->zoom++;
	else if (keycode == ZOOMB)
	{
		if (r->zoom == -9)
			return (0);
		r->zoom--;
	}
	return (0);
}

int		move(int keycode, t_transform *r)
{
	if (keycode == MOVE_UP)
		r->move_vertical -= (WIDTH * 10);
	else if (keycode == MOVE_RIGHT)
		r->move_horizontal += 10;
	else if (keycode == MOVE_DOWN)
		r->move_vertical += (WIDTH * 10);
	else if (keycode == MOVE_LEFT)
		r->move_horizontal -= 10;
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	static	t_transform	r;

	if (keycode == ESC)
		exit(0);
	else if (keycode == UP)
		r.r_x += ROTATE;
	else if (keycode == DOWN)
		r.r_x -= ROTATE;
	else if (keycode == LEFT)
		r.r_y += ROTATE;
	else if (keycode == RIGHT)
		r.r_y -= ROTATE;
	else if (keycode == ZUP)
		r.r_z += ROTATE;
	else if (keycode == ZDOWN)
		r.r_z -= ROTATE;
	zoom(keycode, &r);
	colour(keycode, &r);
	move(keycode, &r);
	ft_clear(e, &r);
	draw(e, &r);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}
