/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:11:07 by tvogel            #+#    #+#             */
/*   Updated: 2022/02/06 00:39:44 by tvogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

void	draw_map(t_config *conf)
{
	t_map	map;
	int		i;
	int		j;
	int		r;

	i = 0;
	map = conf->map;
	r = conf->tile_size;
	while (map.map[i])
	{
		j = 0;
		while (map.map[i][j])
		{
			if (map.map[i][j] == '1')
				render_rect(conf->graph, (t_rect){j * r, i * r, r, r,
					0x00AA1512});
			else
				render_rect(conf->graph, (t_rect){j * r, i * r, r, r,
					0x00FFFFFF});
			j++;
		}
		i++;
	}
	return ;
}

void	draw_player(t_config *conf, t_player *player)
{
	draw_line(conf->graph, (t_point){
		player->x,
		player->y
	}, (t_point){
		player->x + cos(player->rotation_speed) * 50,
		player->y + sin(player->rotation_speed) * 50
	}, 0x02222FF);
}
