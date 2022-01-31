/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:30:22 by tvogel            #+#    #+#             */
/*   Updated: 2022/01/31 14:20:10 by tvogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_there_wall(t_config *c, float x, float y)
{
	int	index_x;
	int	index_y;

	if (x < 0 || x > SCR_WIDTH || y < 0 || y > SCR_HEIGHT)
		return (1);
	index_x = floor(x + 0.4);
	index_y = floor(y + 0.4);
	if (c->map.map[index_y][index_x] == '1')
	{
		return (1);
	}
	return (0);
}

int	move_player(t_config *conf, t_player *p, t_map *m)
{
	float	move_step;
	float	new_player_x;
	float	new_player_y;

	p->rotation_ang += p->turn_dir * p->turn_speed;
	move_step = p->walk_dir * p->walk_speed;
	new_player_x = p->x + cos(p->rotation_ang) * move_step;
	new_player_y = p->y + sin(p->rotation_ang) * move_step;
	if (m->map[(int)new_player_y][(int)new_player_x]
		&& is_there_wall(conf, new_player_x, new_player_y) != 1)
	{
		p->x = new_player_x;
		p->y = new_player_y;
	}
	return (0);
}
