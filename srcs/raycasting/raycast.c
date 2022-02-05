/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:39:09 by tvogel            #+#    #+#             */
/*   Updated: 2022/02/05 23:53:13 by tvogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	cast_single_ray(t_config *c, t_ray *ray)
{
	check_orientation(ray, ray->angle);
	ray->angle = normalize_angle(ray->angle);
	check_horizontal(c, ray);
	check_vertical(c, ray);
}

void	init_ray(t_ray *r)
{
	r->hor_wall_x = 0;
	r->hor_wall_y = 0;
	r->ver_wall_x = 0;
	r->ver_wall_y = 0;
	r->is_ray_down = 0;
	r->is_ray_right = 0;
	return ;
}

void	cast_rays(t_config *c, t_player *p)
{
	int		id;
	float	ray_angle;

	id = 0;
	ray_angle = p->rotation_ang - (p->fov / 2);
	while (id < 1)
	{
		init_ray(&c->rays[id]);
		c->rays[id].angle = ray_angle;
		cast_single_ray(c, &c->rays[id]);
		ray_angle += p->fov / SCR_WIDTH;
		id++;
	}
}
