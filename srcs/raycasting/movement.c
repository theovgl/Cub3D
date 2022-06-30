/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:30:22 by tvogel            #+#    #+#             */
/*   Updated: 2022/06/24 16:01:12 by tvogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_movement(t_map *m, int x, int y)
{
	if (m->map[x][y] != '1')
		return (1);
	return (0);
}

void	move_forward(t_player *p, t_map *m)
{
	if (check_movement(m, (int)(p->x + p->dir_x * p->walk_speed), (int)p->y))
		p->x += p->dir_x * p->walk_speed;
	if (check_movement(m, (int)p->x, (int)(p->y + p->dir_y * p->walk_speed)))
		p->y += p->dir_y * p->walk_speed;
}

void	move_backward(t_player *p, t_map *m)
{
	if (check_movement(m, (int)(p->x - p->dir_x * p->walk_speed), (int)p->y))
		p->x -= p->dir_x * p->walk_speed;
	if (check_movement(m, (int)p->x, (int)(p->y - p->dir_y * p->walk_speed)))
		p->y -= p->dir_y * p->walk_speed;
}

void	shift(t_player *p, t_map *m)
{
	
}

void	rotate(t_player *p, int direction)
{
	double	old_direction;
	double	old_plane;

	old_direction = p->dir_x;
	old_plane = p->plane_x;
	if (direction == 1)
	{
		p->dir_x = p->dir_x * cos(-p->rotation_speed)
			- p->dir_y * sin(-p->rotation_speed);
		p->dir_y = old_direction * sin(-p->rotation_speed)
			+ p->dir_y * cos(-p->rotation_speed);
		p->plane_x = p->plane_x * cos(-p->rotation_speed)
			- p->plane_y * sin(-p->rotation_speed);
		p->plane_y = old_plane * sin(-p->rotation_speed)
			+ p->plane_y * cos(-p->rotation_speed);
	}
	else if (direction == 0)
	{
		p->dir_x = p->dir_x * cos(p->rotation_speed)
			- p->dir_y * sin(p->rotation_speed);
		p->dir_y = old_direction * sin(p->rotation_speed)
			+ p->dir_y * cos(p->rotation_speed);
		p->plane_x = p->plane_x * cos(p->rotation_speed)
			- p->plane_y * sin(p->rotation_speed);
		p->plane_y = old_plane * sin(p->rotation_speed)
			+ p->plane_y * cos(p->rotation_speed);
	}
}
