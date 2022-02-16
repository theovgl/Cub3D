/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_dimensions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:08:31 by tvogel            #+#    #+#             */
/*   Updated: 2022/02/16 17:33:50 by tvogel           ###   ########.fr       */
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

float	fix_fisheye(t_player p, t_ray ray, float distance)
{
	int	result;

	result = cos(ray.angle - p.rotation_ang) * distance;
	return (result);
}

int	get_wall_height(t_config *c, t_ray ray, float plane_dist)
{
	float	wall_height;
	int		wall_render_height;

	wall_height = (c->tile_size / fix_fisheye(c->player,
				ray, ray.distance) * plane_dist);
	wall_render_height = (int)wall_height;
	return (wall_render_height);
}

void	generate_walls(t_config *c, t_ray *rays)
{
	int		i;
	float	plane_distance;
	int		wall_render_height;
	int		wall_top;
	int		wall_bottom;

	i = 0;
	plane_distance = (SCR_WIDTH / 2) / tan(c->player.fov / 2);
	while (i < SCR_WIDTH)
	{
		wall_render_height = get_wall_height(c, rays[i], plane_distance);
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
