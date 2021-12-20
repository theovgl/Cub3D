/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 10:28:39 by tvogel            #+#    #+#             */
/*   Updated: 2021/05/19 17:32:56 by tvogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	int		count;
	int		i;

	i = 0;
	count = nmemb * size;
	ptr = malloc(count);
	if (!ptr)
		return (0);
	while (count > 0)
	{
		ptr[i] = 0;
		i++;
		count--;
	}
	return ((void *)ptr);
}
