/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_dimensions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:08:31 by tvogel            #+#    #+#             */
/*   Updated: 2022/02/16 15:58:47 by tvogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_walls(t_config *c, int col, int top, int bottom)
{
	int	i;

	i = top;
	while (i < bottom)
	{
		my_mlx_pixel_put(c->colors_buf, col, i, 0x00FFFFFF);
		i++;
	}
}

void	generate_walls(t_config *c, t_ray *rays)
{
	int		i;
	float	plane_distance;
	float	wall_height;
	int		wall_render_height;
	int		wall_top;
	int		wall_bottom;

	i = 0;
	plane_distance = (SCR_WIDTH / 2) / tan(c->player.fov / 2);
	while (i < SCR_WIDTH)
	{
		wall_height = (c->tile_size / rays[i].distance) * plane_distance;
		wall_render_height = (int)wall_height;
		wall_top = (SCR_HEIGHT / 2) - (wall_render_height / 2);
		if (wall_top < 0)
			wall_top = 0;
		wall_bottom = (SCR_HEIGHT / 2) + (wall_render_height / 2);
		if (wall_bottom > SCR_HEIGHT)
			wall_bottom = SCR_HEIGHT;
		draw_walls(c, i, wall_top, wall_bottom);
		i++;
	}
}

int	init_colors_buffer(t_config *c)
{
	c->colors_buf.mlx_img = mlx_new_image(c->graph.mlx, SCR_WIDTH, SCR_HEIGHT);
	c->colors_buf.addr = mlx_get_data_addr(c->colors_buf.mlx_img,
			&c->colors_buf.bpp, &c->colors_buf.line_len, &c->colors_buf.endian);
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
			if (y < SCR_HEIGHT / 2)
				my_mlx_pixel_put(c->colors_buf, x, y, 0x0063ACFF);
			else
				my_mlx_pixel_put(c->colors_buf, x, y, 0x006DB352);
			y++;
		}
		x++;
	}
}
