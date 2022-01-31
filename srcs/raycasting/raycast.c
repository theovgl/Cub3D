/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:39:09 by tvogel            #+#    #+#             */
/*   Updated: 2022/01/31 13:29:08 by tvogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	normalize_angle(float angle)
{
	angle = remainder(angle, (2 * M_PI));
	if (angle <= 0)
		angle += 2 * M_PI;
	return (angle);
}

void	check_horizontal(t_config *c, t_ray *ray)
{

}

void	check_orientation(t_ray *r)
{
	if (r->r_angle > 0 && r->r_angle < M_PI)
		r->is_ray_down = 1;
	else
		r->is_ray_down = 0;
	r->is_ray_up = !r->is_ray_down;
	if (r->r_angle > (3 * M_PI) / 2 || r->r_angle < M_PI / 2)
		r->is_ray_right = 1;
	else
		r->is_ray_right = 0;
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
	printf("%d, %d\n", x_to_check, y_to_check);
	if (c->map.map[x_to_check][y_to_check] == '1')
		return (1);
	return (0);
}

void	cast_single_ray(t_config *c, t_ray *ray, int id)
{
	float	y_intercept;
	float	x_intercept;
	float	y_step;
	float	x_step;
	float	next_hor_x;
	float	next_hor_y;

	check_orientation(ray);
	//ray->r_angle = normalize_angle(c->player.rotation_ang - (c->player.fov / 2));
	y_intercept = floor(c->player.y / c->tile_size) * c->tile_size;
	if (ray->is_ray_down)
		y_intercept += c->tile_size;
	//if (ray->r_angle == 0)
	//	ray->r_angle = 0.00000001;
	x_intercept = c->player.x + (y_intercept - c->player.y) / tan(ray->r_angle);
	//printf("p.x: %f, p.y: %f\n", c->player.x, c->player.y);
	//printf("x_int: %f, y_int: %f, a: %f\n", x_intercept, y_intercept, ray->r_angle);

	y_step = c->tile_size;
	if (ray->is_ray_up)
		y_step *= -1;
	x_step = c->tile_size / tan(ray->r_angle);
	if (ray->is_ray_left && x_step > 0)
		x_step *= -1;
	else if (ray->is_ray_right && x_step < 0)
		x_step *= -1;
	next_hor_x = x_intercept;
	next_hor_y = y_intercept;
	if (ray->is_ray_up)
		next_hor_y--;
	while (next_hor_x >= 0 && next_hor_x <= SCR_WIDTH
		&& next_hor_y >= 0 && next_hor_y <= SCR_HEIGHT)
	{
		if (check_for_wall(c, next_hor_x, next_hor_y))
		{
			ray->hit_hor = 1;
			ray->wallHitX = next_hor_x;
			ray->wallHitY = next_hor_y;
			break;
		}
		else
		{
			next_hor_x += x_step;
			next_hor_y += y_step;
		}
	}
	draw_line(c->graph, (t_point){
		c->player.x * c->tile_size + (c->tile_size / 2) / 2,
		c->player.y * c->tile_size + (c->tile_size / 2) / 2
	}, (t_point){
		ray->wallHitX * c->tile_size, ray->wallHitY * c->tile_size
	}, 0x00FFA701);

	//printf("right: %i, down: %i\n", ray->is_ray_right, ray->is_ray_down);
	// check_horizontal(c, ray);
}

void	init_ray(t_config *c, t_ray *r, t_player *p)
{
	r->r_angle = normalize_angle(p->rotation_ang - (p->fov / 2));
	r->wallHitX = 0;
	r->wallHitY = 0;
	r->distance = 0;
	return ;
}

void	cast_rays(t_config *c, t_player *p)
{
	int		id;
	int		size;

	id = 0;
	size = c->tile_size / 2;
	while (id < 1)
	{
		init_ray(c, &c->rays[id], p);
		cast_single_ray(c, &c->rays[id], id);
		c->rays[id].r_angle += p->fov / SCR_WIDTH;
		id++;
	}
}
