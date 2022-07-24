/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_dimensions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:08:31 by tvogel            #+#    #+#             */
/*   Updated: 2022/07/16 15:34:16 by tvogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_walls(t_config *c)
{
	mlx_put_image_to_window(c->graph.mlx,
		c->graph.win, c->colors_buf.mlx_img, 0, 0);
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
