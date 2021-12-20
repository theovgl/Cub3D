/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 08:42:43 by tvogel            #+#    #+#             */
/*   Updated: 2020/11/26 16:21:17 by tvogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int		i;
	char	*destchar;
	char	*srcchar;

	destchar = (char *)dest;
	srcchar = (char *)src;
	i = 0;
	if ((!dest && !src))
		return (NULL);
	while (n > 0)
	{
		destchar[i] = srcchar[i];
		i++;
		n--;
	}
	return (dest);
}
