/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroguszk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 17:24:34 by jroguszk          #+#    #+#             */
/*   Updated: 2018/01/30 15:21:46 by jroguszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_putpixel(double x, double y, t_env *e, t_transform *r)
{
	if (ft_round(x + (y * WIDTH) + r->move_vertical
		+ r->move_horizontal + e->centre) > HEIGHT * WIDTH
		|| ft_round(x + (y * WIDTH) + r->move_vertical
			+ r->move_horizontal + e->centre) < 0
		|| POS(x + r->move_horizontal + (WIDTH / 2)) >= WIDTH
		|| x + r->move_horizontal + (WIDTH / 2) <= 0)
		return ;
	if (r->colour == 0)
		return ;
	e->addr[ft_round(x + (y * WIDTH) + e->centre
		+ r->move_horizontal + r->move_vertical)] = r->colour;
}

void	ft_clear(t_env *e, t_transform *r)
{
	int		i;
	int		j;

	i = 0;
	j = HEIGHT * WIDTH;
	while (i < j)
	{
		e->addr[i] = r->background;
		i++;
	}
}

void	draw_horizontal(double x1, double y1, t_env *e, t_transform *r)
{
	double	y;
	double	x;
	double	slope;
	double	x2;
	double	y2;

	x2 = e->x_2;
	y2 = e->y_2;
	if (x1 >= x2)
		ft_swap_double(&x1, &x2, &y1, &y2);
	x = x1;
	slope = (y2 - y1) / (x2 - x1);
	while (x++ < x2)
	{
		y = ft_round(slope * (x - x1) + y1);
		ft_putpixel(x, y, e, r);
	}
	if (y1 >= y2)
		ft_swap_double(&x1, &x2, &y1, &y2);
	y = y1;
	while (y++ < y2)
	{
		x = ft_round((y - y1) / slope + x1);
		ft_putpixel(x, y, e, r);
	}
}

void	draw_vertical(double x1, double y1, t_env *e, t_transform *r)
{
	double	y;
	double	x;
	double	slope;
	double	x2;
	double	y2;

	x2 = e->grid2[e->i][e->j];
	y2 = e->grid3[e->i][e->j];
	if (x1 > x2)
		ft_swap_double(&x1, &x2, &y1, &y2);
	x = x1;
	slope = (y2 - y1) / (x2 - x1);
	while (x++ < x2)
	{
		y = ft_round(slope * (x - x1) + y1);
		ft_putpixel(x, y, e, r);
	}
	if (y1 >= y2)
		ft_swap_double(&x1, &x2, &y1, &y2);
	y = y1;
	while (y++ < y2)
	{
		x = ft_round((y - y1) / slope + x1);
		ft_putpixel(x, y, e, r);
	}
}

void	draw(t_env *e, t_transform *r)
{
	e->i = 0;
	e->centre = (((WIDTH * HEIGHT) / 2) + WIDTH) / 2;
	while (e->i < e->y)
	{
		e->j = 0;
		while (e->j < e->x)
		{
			rotate(e, r);
			if (e->j == 0)
			{
				e->tmpx = e->x_2;
				e->tmpy = e->y_2;
			}
			if (e->j != 0)
				draw_horizontal(e->tmpx, e->tmpy, e, r);
			if (e->i != 0)
				draw_vertical(e->grid2[e->i - 1][e->j],
				e->grid3[e->i - 1][e->j], e, r);
			e->j++;
			e->tmpx = e->x_2;
			e->tmpy = e->y_2;
		}
		e->i++;
	}
}
