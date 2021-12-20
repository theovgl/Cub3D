/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 17:18:44 by tvogel            #+#    #+#             */
/*   Updated: 2020/11/18 19:42:29 by tvogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		j;
	char		*bigstring;
	char		*littlestring;

	bigstring = (char *)big;
	littlestring = (char *)little;
	i = 0;
	if (littlestring[0] == '\0')
		return (bigstring);
	while (bigstring[i] != '\0' && i < len)
	{
		j = 0;
		while (littlestring[j] == bigstring[i + j] && (i + j) < len)
		{
			if (littlestring[j + 1] == '\0')
			{
				return (bigstring + i);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}
