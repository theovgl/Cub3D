/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_intersection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 00:37:58 by tvogel            #+#    #+#             */
/*   Updated: 2022/02/06 00:38:14 by tvogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

void	check_horizontal(t_config *c, t_ray *r)
{
	float	next_hor_x;
	float	next_hor_y;

	get_intercept(c, r, 0);
	get_delta(c, r, 0);
	next_hor_x = r->x_intercept;
	next_hor_y = r->y_intercept;
	if (!r->is_ray_down)
		next_hor_y--;
	while (next_hor_x >= 0 && next_hor_x <= c->map.map_width * c->tile_size
		&& next_hor_y >= 0 && next_hor_y <= c->map.map_height * c->tile_size)
	{
		if (check_for_wall(c, next_hor_x, next_hor_y))
		{
			r->hit_hor = 1;
			r->hor_wall_x = next_hor_x;
			r->hor_wall_y = next_hor_y;
			break ;
		}
		else
		{
			next_hor_x += r->dx;
			next_hor_y += r->dy;
		}
	}
}

void	check_vertical(t_config *c, t_ray *r)
{
	float	next_ver_x;
	float	next_ver_y;

	get_intercept(c, r, 1);
	get_delta(c, r, 1);
	next_ver_x = r->x_intercept;
	next_ver_y = r->y_intercept;
	if (!r->is_ray_right)
		next_ver_x--;
	while (next_ver_x >= 0 && next_ver_x <= c->map.map_width * c->tile_size
		&& next_ver_y >= 0 && next_ver_y <= c->map.map_height * c->tile_size)
	{
		if (check_for_wall(c, next_ver_x, next_ver_y))
		{
			r->hit_ver = 1;
			r->ver_wall_x = next_ver_x;
			r->ver_wall_y = next_ver_y;
			break ;
		}
		else
		{
			next_ver_x += r->dx;
			next_ver_y += r->dy;
		}
	}
}
