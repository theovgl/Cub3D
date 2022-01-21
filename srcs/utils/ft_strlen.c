/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 17:55:21 by tvogel            #+#    #+#             */
/*   Updated: 2021/12/22 20:47:30 by tvogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	ft_strlen(const char *src)
{
	int	i;

	i = 0;
	if (!src)
		return (0);
	while (src[i])
	{
		i++;
	}
	return (i);
}
