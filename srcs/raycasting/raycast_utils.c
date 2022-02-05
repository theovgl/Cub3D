/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 21:47:02 by tvogel            #+#    #+#             */
/*   Updated: 2022/02/05 12:12:03 by tvogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

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
	{
		r->is_ray_down = 1;
		// printf("down\n");
	}
	else
	{
		r->is_ray_down = 0;
		// printf("up\n");
	}
	r->is_ray_up = !r->is_ray_down;
	if (angle > (3 * M_PI) / 2 || angle < M_PI / 2)
	{
		r->is_ray_right = 1;
		// printf("right\n");
	}
	else
	{
		r->is_ray_right = 0;
		// printf("left\n");
	}
	r->is_ray_left = !r->is_ray_right;
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
