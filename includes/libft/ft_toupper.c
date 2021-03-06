/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jroguszk <jroguszk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 09:10:23 by jroguszk          #+#    #+#             */
/*   Updated: 2017/12/08 11:04:40 by jroguszk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 'a' + 'A');
	else
		return (c);
}
