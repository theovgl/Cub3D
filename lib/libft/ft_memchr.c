/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:43:29 by tvogel            #+#    #+#             */
/*   Updated: 2020/11/18 19:43:13 by tvogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	cc;
	int				i;

	i = 0;
	str = (unsigned char *)s;
	cc = (unsigned char)c;
	while (n > 0)
	{
		if (str[i] == cc)
		{
			return (&str[i]);
		}
		n--;
		i++;
	}
	return (NULL);
}
