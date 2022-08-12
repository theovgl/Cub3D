/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiju-du <abiju-du@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:30:22 by tvogel            #+#    #+#             */
/*   Updated: 2022/08/12 13:50:14 by abiju-du         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_movement(t_map *m, int x, int y)
{
	if (m->map[y][x] != '1')
		return (1);
	return (0);
}

void	move_forward(t_player *p, t_map *m)
{
	if (check_movement(m, (int)(p->x + p->dir_x
			* p->walk_speed), (int)p->y))
		p->x += p->dir_x * p->walk_speed;
	if (check_movement(m, (int)p->x, (int)(p->y + p->dir_y
			* p->walk_speed)))
		p->y += p->dir_y * p->walk_speed;
}

void	shift(t_player *p, t_map *m)
{
	if (check_movement(m, (int)(p->x - p->plane_x
			* (p->strafe_speed)), (int)p->y))
		p->x -= p->plane_x * p->strafe_speed;
	if (check_movement(m, (int)p->x, (int)(p->y - p->plane_y
			* (p->strafe_speed))))
		p->y -= p->plane_y * p->strafe_speed;
}

void	rotate(t_player *p)
{
	double	old_direction;
	double	old_plane;

	old_direction = p->dir_x;
	old_plane = p->plane_x;
	p->dir_x = p->dir_x * cos(p->rotation_speed)
		- p->dir_y * sin(p->rotation_speed);
	p->dir_y = old_direction * sin(p->rotation_speed)
		+ p->dir_y * cos(p->rotation_speed);
	p->plane_x = p->plane_x * cos(p->rotation_speed)
		- p->plane_y * sin(p->rotation_speed);
	p->plane_y = old_plane * sin(p->rotation_speed)
		+ p->plane_y * cos(p->rotation_speed);
}
