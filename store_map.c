/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroguszk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 17:26:54 by jroguszk          #+#    #+#             */
/*   Updated: 2018/01/25 17:26:55 by jroguszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_size(char *argv)
{
	t_var	b;
	int		i;

	i = 0;
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
	int		i;

	e->x = 0;
	i = 0;
	b.tmp = ft_strsplit(line, ' ');
	while (b.tmp[i])
		i++;
	if ((e->grid[e->y] = (int*)malloc(sizeof(int*) * i + 1)) == NULL
	|| (e->grid2[e->y] = (int*)malloc(sizeof(int*) * i + 1)) == NULL
	|| (e->grid3[e->y] = (int*)malloc(sizeof(int*) * i + 1)) == NULL)
		return ;
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
	if ((e->grid = (int**)malloc(sizeof(int*) * (b.size + 1))) == NULL
	|| (e->grid2 = (int**)malloc(sizeof(int*) * (b.size + 1))) == NULL
	|| (e->grid3 = (int**)malloc(sizeof(int*) * (b.size + 1))) == NULL)
		return (0);
	while ((b.ret = get_next_line(b.fd, &b.line)) > 0)
	{
		if (b.ret == -1)
			return (0);
		store_array(b.line, e);
		e->y++;
	}
	e->grid[e->y] = NULL;
	e->grid2[e->y] = NULL;
	e->grid[e->y] = NULL;
	free(b.line);
	close(b.fd);
	return (0);
}
