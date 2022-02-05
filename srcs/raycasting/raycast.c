/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:39:09 by tvogel            #+#    #+#             */
/*   Updated: 2022/02/05 14:15:47 by tvogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cast_single_ray(t_config *c, t_ray *ray, float angle)
{
	float	y_intercept;
	float	x_intercept;
	float	dy;
	float	dx;
	float	next_hor_x;
	float	next_hor_y;

	check_orientation(ray, angle);
	y_intercept = floor(c->player.y / c->tile_size) * c->tile_size;
	angle = normalize_angle(angle);
	if (ray->is_ray_down)
		y_intercept += c->tile_size;
	x_intercept = c->player.x + (y_intercept - c->player.y) / tan(angle);

	dy = c->tile_size;
	if (ray->is_ray_down == 0)
		dy *= -1;

	dx = c->tile_size / tan(angle);
	if (ray->is_ray_left && dx > 0)
		dx *= -1;
	else if (ray->is_ray_right && dx < 0)
		dx *= -1;
	next_hor_x = x_intercept;
	next_hor_y = y_intercept;
	while (next_hor_x >= 0 && next_hor_x <= c->map.map_width * c->tile_size
		&& next_hor_y >= 0 && next_hor_y <= c->map.map_height * c->tile_size)
	{
		if (ray->is_ray_up)
			next_hor_y--;
		if (check_for_wall(c, next_hor_x, next_hor_y))
		{
			ray->hit_hor = 1;
			ray->wallHitX = next_hor_x;
			ray->wallHitY = next_hor_y;
			break ;
		}
		else
		{
			next_hor_x += dx;
			next_hor_y += dy;
		}
	}
}

void	init_ray(t_config *c, t_ray *r, t_player *p)
{
	r->wallHitX = 0;
	r->wallHitY = 0;
	r->distance = 0;
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
		init_ray(c, &c->rays[id], p);
		c->rays[id].r_angle = ray_angle;
		cast_single_ray(c, &c->rays[id], c->rays[id].r_angle);
		ray_angle += p->fov / SCR_WIDTH;
		id++;
	}
}
