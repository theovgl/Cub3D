/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_dimensions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:08:31 by tvogel            #+#    #+#             */
/*   Updated: 2022/02/07 16:40:19 by tvogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_colors_buffer(t_config *c)
{
	c->colors_buffer = malloc(sizeof(u_int32_t)
			* (u_int32_t)SCR_WIDTH * (u_int32_t)SCR_HEIGHT);
	if (!c->colors_buffer)
		return(error_handling(c, 1, "Malloc failed"));
	return (0);
}

void	clear_buffer(t_config *c)
{
	int	x;
	int	y;

	x = 0;
	while (x < SCR_WIDTH)
	{
		y = 0;
		while (y < SCR_WIDTH)
		{
			c->colors_buffer[(SCR_WIDTH * y) + x] = 0xFF000000;
			y++;
		}
		x++;
	}
}
