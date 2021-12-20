/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 13:29:30 by tvogel            #+#    #+#             */
/*   Updated: 2020/11/23 12:14:20 by tvogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		length;

	str = (char *)s;
	length = ft_strlen(str);
	while (length >= 0)
	{
		if (str[length] == (char)c)
		{
			return (str + length);
		}
		length--;
	}
	return (NULL);
}
