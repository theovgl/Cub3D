/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_dimensions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:08:31 by tvogel            #+#    #+#             */
/*   Updated: 2022/06/28 18:11:01 by tvogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_walls(t_config *c, t_ray *ray)
{
	int	i;
	int	j;

	i = 0;
	while (i < SCR_WIDTH)
	{
		j = c->rays[i].top;
		while (j < c->rays[i].bottom)
		{
			if (c->rays[i].side == 0)
				my_mlx_pixel_put(c->colors_buf, i, j, c->rays[i].color);
			else
				my_mlx_pixel_put(c->colors_buf, i, j, c->rays[i].color);
			j++;
		}
		i++;
	}
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
			if (y < SCR_HEIGHT / 2)
				my_mlx_pixel_put(c->colors_buf, x, y, c->ceiling.hex);
			else
				my_mlx_pixel_put(c->colors_buf, x, y, c->floor.hex);
			y++;
		}
		x++;
	}
}
