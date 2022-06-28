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

static int check_movement(t_map *m, int x, int y)
{
	if (x > m->map_width || y > m->map_height || x < 0 || y < 0)
		return (0);
	if (m->map[y][x] != 1)
	{
		return (1);
	}
	return (0);
}

void move_forward(t_config *c, t_player *p, t_map *m)
{
	if (check_movement(m, (int)(p->x + p->dir_x * p->walk_speed), (int)p->y))
		p->x += p->dir_x * p->walk_speed;
	if (check_movement(m, (int)p->x, (int)(p->y + p->dir_y * p->walk_speed)))
		p->y += p->dir_y * p->walk_speed;
}
