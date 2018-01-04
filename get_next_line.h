/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroguszk <jroguszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 15:29:57 by jroguszk          #+#    #+#             */
/*   Updated: 2017/12/15 11:51:54 by jroguszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __GET_NEXT_LINE_H
# define __GET_NEXT_LINE_H
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "./libft/includes/libft.h"

# define BUFF_SIZE 8

typedef	struct	s_struct
{
	int			i[2147483648];
	int			ret[2147483648];
	char		*buf[2147483648];
}				t_b;

int				get_next_line(const int fd, char **line);

#endif
