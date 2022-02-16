/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:39:09 by tvogel            #+#    #+#             */
/*   Updated: 2022/02/16 17:47:05 by tvogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	get_distance(float x1, float y1, float x2, float y2)
{
	float	distance;
	float	y_distance;
	float	x_distance;

	x_distance = (x2 - x1) * (x2 - x1);
	y_distance = (y2 - y1) * (y2 - y1);
	distance = sqrt(x_distance + y_distance);
	return (distance);
}

void	best_distance(t_config *c, t_ray *ray)
{
	float	hor_hit_distance;
	float	ver_hit_distance;

	if (ray->hit_hor)
		hor_hit_distance = get_distance(c->player.x, c->player.y,
				ray->hor_wall_x, ray->hor_wall_y);
	else
		hor_hit_distance = (float)INT_MAX;
	if (ray->hit_ver)
		ver_hit_distance = get_distance(c->player.x, c->player.y,
				ray->ver_wall_x, ray->ver_wall_y);
	else
		ver_hit_distance = (float)INT_MAX;
	if (ver_hit_distance < hor_hit_distance)
	{
		ray->distance = ver_hit_distance;
		ray->x = ray->ver_wall_x;
		ray->y = ray->ver_wall_y;
		ray->hit_hor = 0;
	}
	else
	{
		ray->distance = hor_hit_distance;
		ray->x = ray->hor_wall_x;
		ray->y = ray->hor_wall_y;
	}
}

void	cast_single_ray(t_config *c, t_ray *ray)
{
	ray->angle = normalize_angle(ray->angle);
	check_orientation(ray, ray->angle);
	check_horizontal(c, ray);
	check_vertical(c, ray);
	best_distance(c, ray);
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
	while (id < SCR_WIDTH)
	{
		init_ray(&c->rays[id]);
		c->rays[id].angle = ray_angle;
		cast_single_ray(c, &c->rays[id]);
		ray_angle += p->fov / SCR_WIDTH;
		id++;
	}
}
