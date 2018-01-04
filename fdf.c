/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroguszk <jroguszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 10:10:47 by jroguszk          #+#    #+#             */
/*   Updated: 2018/01/04 17:27:50 by jroguszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft/includes/libft.h"
#include "includes/get_next_line.h"
#include "minilibx/mlx.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef	struct s_coord
{
	int x;
	int y;
	int z;
}				t_coord;

int		get_image(char *argv, char **grid)
{
	int				fd;
	int				ret;
	int				i;
	int				j;
	int				k;
	int				l;
	static	t_coord	a;
	char			**tmp;
	char			*line;

	i = 0;
	j = 0;
	k = 0;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (0);
	line = ft_strnew(BUFF_SIZE);
	while ((ret = get_next_line(fd, &line)))
	{
		a.y++;
		*tmp = ft_strnew(ret);
		tmp = ft_strsplit(line, ' ');
		while (tmp[i])
		{
			l = ft_atoi(tmp[i]);
			if (l > j)
				j = l;
			if (l < k)
				k = l;
			i++;
		}
		if (i > a.x)
			a.x = i;
		i = 0;
		free(tmp);
	}
	free(line);
	k *= -1;
	a.z = k + j;
	*grid = ft_strnew(a.x * a.y * a.z);
	printf("%d\n", a.x);
	printf("%d\n", a.y);
	printf("%d\n", a.z);
	return (0);
}

int		main(int argc, char **argv)
{
	static	t_coord	a;
	char	*grid;

	get_image(argv[1], &grid);
	return (0);

}