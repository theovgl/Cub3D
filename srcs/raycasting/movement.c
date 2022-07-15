/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiju-du <abiju-du@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:30:22 by tvogel            #+#    #+#             */
/*   Updated: 2022/07/15 19:19:19 by abiju-du         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_movement(t_map *m, int x, int y)
{
	if (m->map[x][y] != '1')
		return (1);
	return (0);
}

void	move_forward(t_player *p, t_map *m, int forward)
{
	if (check_movement(m, (int)(p->x + p->dir_x
			* p->walk_speed * forward), (int)p->y))
		p->x += p->dir_x * p->walk_speed * forward;
	if (check_movement(m, (int)p->x, (int)(p->y + p->dir_y
			* p->walk_speed * forward)))
		p->y += p->dir_y * p->walk_speed * forward;
}

void	shift(t_player *p, t_map *m, int right)
{
	if (check_movement(m, (int)(p->x + p->plane_x
			* (p->walk_speed + (right * 0.5))), (int)p->y))
		p->x += p->plane_x * p->walk_speed * right;
	if (check_movement(m, (int)p->x, (int)(p->y + p->plane_y
			* (p->walk_speed + (right * 0.5)))))
		p->y += p->plane_y * p->walk_speed * right;
}

static void	other_dir(t_player *p, double od, double op)
{
	p->dir_x = p->dir_x * cos(p->rotation_speed)
		- p->dir_y * sin(p->rotation_speed);
	p->dir_y = od * sin(p->rotation_speed)
		+ p->dir_y * cos(p->rotation_speed);
	p->plane_x = p->plane_x * cos(p->rotation_speed)
		- p->plane_y * sin(p->rotation_speed);
	p->plane_y = op * sin(p->rotation_speed)
		+ p->plane_y * cos(p->rotation_speed);
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
		other_dir(p, old_direction, old_plane);
}
