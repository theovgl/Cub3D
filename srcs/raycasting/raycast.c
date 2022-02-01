/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:39:09 by tvogel            #+#    #+#             */
/*   Updated: 2022/02/01 22:20:14 by tvogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"







void	cast_single_ray(t_config *c, t_ray *ray, float angle)
{
	float	y_intercept;
	float	x_intercept;
	float	y_step;
	float	x_step;
	float	next_hor_x;
	float	next_hor_y;

	angle = normalize_angle(angle);
	check_orientation(ray, angle);
	y_intercept = floor(c->player.y / c->tile_size) * c->tile_size;
	if (ray->is_ray_down)
		y_intercept += c->tile_size;
	if (angle == 0 || angle == M_PI)
		angle = 1e30;
	x_intercept = c->player.x + (y_intercept - c->player.y) / tan(angle);
	//printf("x_int: %f, y_int: %f, a: %f\n", x_intercept, y_intercept, angle);

	y_step = c->tile_size;
	if (ray->is_ray_up)
		y_step *= -1;

	x_step = c->tile_size / tan(angle);
	if (ray->is_ray_left && x_step > 0)
		x_step *= -1;
	else if (ray->is_ray_right && x_step < 0)
		x_step *= -1;

	next_hor_x = x_intercept;
	next_hor_y = y_intercept;
	if (ray->is_ray_up)
		next_hor_y--;
	while (next_hor_x >= 0 && next_hor_x <= c->map.map_width * c->tile_size
		&& next_hor_y >= 0 && next_hor_y <= c->map.map_height * c->tile_size)
	{
		if (check_for_wall(c, next_hor_x, next_hor_y))
		{
			ray->hit_hor = 1;
			ray->wallHitX = next_hor_x;
			ray->wallHitY = next_hor_y;
			break ;
		}
		else
		{
			next_hor_x += x_step;
			next_hor_y += y_step;
		}
	}
}

void	init_ray(t_config *c, t_ray *r, t_player *p)
{
	r->wallHitX = 0;
	r->wallHitY = 0;
	r->distance = 0;
	return ;
}

void	cast_rays(t_config *c, t_player *p)
{
	int		id;
	int		size;
	float	ray_angle;

	id = 0;
	size = c->tile_size / 2;
	ray_angle = p->rotation_ang - (p->fov / 2);
	while (id < SCR_WIDTH)
	{
		init_ray(c, &c->rays[id], p);
		cast_single_ray(c, &c->rays[id], ray_angle);
		ray_angle += p->fov / SCR_WIDTH;
		id++;
	}
}
