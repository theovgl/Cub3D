/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:11:07 by tvogel            #+#    #+#             */
/*   Updated: 2022/01/27 11:05:59 by tvogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_rect(t_graph g, t_rect rect)
{
	int	i;
	int	j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			my_mlx_pixel_put(g, j++, i, rect.color);
		i++;
	}
	return ;
}

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
	r = SCR_WIDTH / conf->map.map_width;
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
	int	ratio;

	ratio = SCR_WIDTH / conf->map.map_width;
	render_rect(conf->graph, (t_rect){player->x * ratio, player->y * ratio,
		ratio, ratio, 0x00FFBE46});
	draw_line(conf->graph, (t_point){
		player->x * ratio + ratio / 2,
		player->y * ratio + ratio / 2
	}, (t_point){
		player->x * ratio + (ratio / 2) + cos(player->rotation_ang) * 50,
		player->y * ratio + (ratio / 2) + sin(player->rotation_ang) * 50
	}, 0x02222FF);
}

int	render(t_config *conf)
{
	draw_map(conf);
	draw_player(conf, &conf->player);
	mlx_put_image_to_window(conf->graph.mlx, conf->graph.win,
		conf->graph.img.mlx_img, 0, 0);
	return (0);
}
