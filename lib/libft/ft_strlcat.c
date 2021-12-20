/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 13:56:58 by tvogel            #+#    #+#             */
/*   Updated: 2021/05/19 17:41:35 by tvogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	a;
	size_t	j;

	i = 0;
	if (size != 0)
	{
		while (dst[i] && i < size)
			i++;
		a = 0;
		while (src[a] && a + i < size - 1)
		{
			dst[i + a] = src[a];
			a++;
		}
		if (a + i < size)
			dst[a + i] = '\0';
	}
	j = 0;
	while (src[j] != '\0')
		j++;
	return (j + i);
}
