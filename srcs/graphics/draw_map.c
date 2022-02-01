/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:11:07 by tvogel            #+#    #+#             */
/*   Updated: 2022/02/01 18:16:22 by tvogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

void	draw_map(t_config *conf)
{
	t_map	map;
	t_graph	g;
	int		i;
	int		j;
	int		r;

	i = 0;
	g = conf->graph;
	map = conf->map;
	r = conf->tile_size;
	while (map.map[i])
	{
		j = 0;
		while (map.map[i][j])
		{
			if (map.map[i][j] == '1')
				render_rect(g, (t_rect){j * r, i * r, r, r, 0x00AA1512});
			else
				render_rect(g, (t_rect){j * r, i * r, r, r, 0x00FFFFFF});
			j++;
		}
		i++;
	}
	return ;
}

void	draw_player(t_config *conf, t_player *player)
{
	int	size;

	size = conf->tile_size / 2;
	render_rect(conf->graph, (t_rect){player->x,
		player->y,
		size, size, 0x00FFBE46});
	draw_line(conf->graph, (t_point){
		player->x + size / 2,
		player->y + size / 2
	}, (t_point){
		player->x + size / 2 + cos(player->rotation_ang) * 50,
		player->y + size / 2 + sin(player->rotation_ang) * 50
	}, 0x02222FF);
}
