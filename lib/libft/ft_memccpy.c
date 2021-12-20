/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 19:55:08 by tvogel            #+#    #+#             */
/*   Updated: 2020/11/30 12:30:46 by tvogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*destchar;
	unsigned char	*srcchar;

	destchar = (unsigned char *)dest;
	srcchar = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		destchar[i] = srcchar[i];
		if (srcchar[i] == (unsigned char)c)
		{
			return (destchar + i + 1);
		}
		i++;
	}
	return (NULL);
}
