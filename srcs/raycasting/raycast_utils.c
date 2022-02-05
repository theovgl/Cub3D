/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 21:47:02 by tvogel            #+#    #+#             */
/*   Updated: 2022/02/06 00:06:24 by tvogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

void	get_intercept(t_config *c, t_ray *r, int vertical)
{
	if (vertical == 0)
	{
		r->y_intercept = floor(c->player.y / c->tile_size) * c->tile_size;
		if (r->is_ray_down)
			r->y_intercept += c->tile_size;
		r->x_intercept = c->player.x + (r->y_intercept - c->player.y)
			/ tan(r->angle);
	}
	else
	{
		r->x_intercept = floor(c->player.x / c->tile_size) * c->tile_size;
		if (r->is_ray_right)
			r->x_intercept += c->tile_size;
		r->y_intercept = c->player.y + (r->x_intercept - c->player.x)
			* tan(r->angle);
	}
}

void	get_delta(t_config *c, t_ray *r, int vertical)
{
	if (vertical == 0)
	{
		r->dy = c->tile_size;
		if (r->is_ray_down == 0)
			r->dy *= -1;
		r->dx = c->tile_size / tan(r->angle);
		if (!r->is_ray_right && r->dx > 0)
			r->dx *= -1;
		else if (r->is_ray_right && r->dx < 0)
			r->dx *= -1;
	}
	else
	{
		r->dx = c->tile_size;
		if (!r->is_ray_right)
			r->dx *= -1;
		r->dy = c->tile_size * tan(r->angle);
		if (!r->is_ray_down && r->dy > 0)
			r->dy *= -1;
		else if (r->is_ray_down && r->dy < 0)
			r->dy *= -1;
	}
}

float	normalize_angle(float angle)
{
	angle = remainderf(angle, (2 * M_PI));
	if (angle < 0)
		angle += 2 * M_PI;
	return (angle);
}

void	check_orientation(t_ray *r, float angle)
{
	if (angle > 0 && angle < M_PI)
		r->is_ray_down = 1;
	else
		r->is_ray_down = 0;
	if (angle > (3 * M_PI) / 2 || angle < M_PI / 2)
		r->is_ray_right = 1;
	else
		r->is_ray_right = 0;
}

int	check_for_wall(t_config *c, float x, float y)
{
	int	x_to_check;
	int	y_to_check;

	if (x < 0 || x > SCR_WIDTH || y < 0 || y > SCR_HEIGHT)
	{
		return (1);
	}
	x_to_check = floor(x / c->tile_size);
	y_to_check = floor(y / c->tile_size);
	if (x_to_check > c->map.map_width || y_to_check > c->map.map_height)
	{
		return (1);
	}
	if (c->map.map[y_to_check][x_to_check] == '1')
	{
		return (1);
	}
	return (0);
}
