/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:39:09 by tvogel            #+#    #+#             */
/*   Updated: 2022/06/27 19:00:00 by tvogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



// void	cast_single_ray(t_config *c, t_ray *ray)
// {
// 	ray->angle = normalize_angle(ray->angle);
// 	check_orientation(ray, ray->angle);
// 	check_horizontal(c, ray);
// 	check_vertical(c, ray);
// 	best_distance(c, ray);
// }

static void	dda(t_config *c, t_player *p, t_ray *r)
{
	while (r->hit == 0)
	{
		if (r->sidedist_x < r->sidedist_y)
		{
			r->sidedist_x += r->delta_x;
			r->map_x += r->step_x;
			r->side = 0;
		}
		else
		{
			r->sidedist_y += r->delta_y;
			r->map_y += r->step_y;
			r->side = 1;
		}
		printf("%i, %i\n", r->map_x, r->map_y);
		// printf("%c\n", c->map.map[11][0]);
		if (c->map.map[r->map_y][r->map_x] == 1)
			r->hit = 1;
	}
}

static void	get_wall_height(t_player *p, t_ray *r)
{
	int	line_height;
	if (r->side == 0)
		r->perp_wall_dist = r->sidedist_x - r->delta_x;
	else
		r->perp_wall_dist = r->sidedist_y - r->delta_y;

	line_height = (int)(SCR_HEIGHT / r->perp_wall_dist);
	r->top = -line_height / 2 + SCR_HEIGHT / 2;
	if (r->top < 0)
		r->top = 0;
	r->bottom = line_height / 2 + SCR_HEIGHT / 2;
	if (r->bottom >= SCR_HEIGHT)
	{
		r->bottom = SCR_HEIGHT - 1;
	}

}

static void	init_sidedist(t_player *p, t_ray *r)
{
	if (r->rayDir_x < 0)
	{
		r->step_x = -1;
		r->sidedist_x = (p->x - r->map_x) * r->delta_x;
	}
	else
	{
		r->step_x = 1;
		r->sidedist_x = (r->map_x + 1.0 - p->x) * r->delta_x;
	}
	if (r->rayDir_y < 0)
	{
		r->step_y = -1;
		r->sidedist_y = (p->y - r->map_y) * r->delta_y;
	}
	else
	{
		r->step_y = 1;
		r->sidedist_y = (r->map_y + 1.0 - p->y) * r->delta_y;
	}
}

static void	init_ray(t_player *p, t_ray *r, int id)
{
	r->camera_x = 2 * id / (double)SCR_WIDTH - 1;
	r->rayDir_x = p->dir_x + p->plane_x * r->camera_x;
	r->rayDir_y = p->dir_y + p->plane_y * r->camera_x;
	r->map_x = (int)p->x;
	r->map_y = (int)p->y;
	if (r->rayDir_x == 0)
		r->delta_x = (double)INT_MAX;
	else
		r->delta_x = fabs(1 / r->rayDir_x);
	if (r->rayDir_y == 0)
		r->delta_y = (double)INT_MAX;
	else
		r->delta_y = fabs(1 / r->rayDir_y);
	r->hit = 0;

	return ;
}

void	cast_rays(t_config *c, t_player *p)
{
	int		id;

	id = 0;

	//provisoire
	p->dir_x = -1;
	p->dir_y = 0;
	p->plane_x = 0;
	p->plane_y = 0.66;

	while (id < 1)
	{
		init_ray(p, &c->rays[id], id);
		init_sidedist(p, &c->rays[id]);
		dda(c, p, &c->rays[id]);
		get_wall_height(p, &c->rays[id]);
		id++;
	}
}
