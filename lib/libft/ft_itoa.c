/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 14:50:05 by tvogel            #+#    #+#             */
/*   Updated: 2021/05/20 13:41:25 by tvogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	len(unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i + 1);
}

int	is_neg(int n)
{
	if (n < 0)
		n = -n;
	return (n);
}

int	malloc_len(int n)
{
	if (n < 0)
		n = 1;
	else
		n = 0;
	return (n);
}

char	*ft_itoa(int n)
{
	char			*dest;
	unsigned int	length;
	unsigned int	nb;
	unsigned int	i;

	nb = is_neg(n);
	length = len(nb);
	i = 0;
	dest = (char *)malloc(sizeof(char) * length + 1 + malloc_len(n));
	if (!dest)
		return (NULL);
	if (n < 0)
	{
		dest[i] = '-';
		length++;
	}
	i = length - 1;
	while (nb >= 10)
	{
		dest[i--] = nb % 10 + 48;
		nb /= 10;
	}
	dest[i] = nb % 10 + 48;
	dest[length] = '\0';
	return (dest);
}
