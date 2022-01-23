/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:11:07 by tvogel            #+#    #+#             */
/*   Updated: 2022/01/23 15:31:33 by tvogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render_rect(t_graph g, t_rect rect)
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
	return (0);
}

void	draw_map(t_config *conf)
{
	t_map	map;
	t_graph	g;
	int		i;
	int		j;

	i = 0;
	g = conf->graph;
	map = conf->map;
	while (map.map[i])
	{
		j = 0;
		while (map.map[i][j])
		{
			if (map.map[i][j] == '1')
				render_rect(g, (t_rect){j * 10, i * 10, 10, 10, 0x00AA1512});
			else
				render_rect(g, (t_rect){j * 10, i * 10, 10, 10, 0x00FFFFFF});
			j++;
		}
		i++;
	}
	return ;
}

void	draw_player(t_config *conf, t_player *player)
{
	render_rect(conf->graph, (t_rect){player->x * 10 - 10, player->y * 10 - 10,
		10, 10, 0x00AAFF99});
}

int	render(t_config *conf)
{
	draw_map(conf);
	draw_player(conf, &conf->player);
	mlx_put_image_to_window(conf->graph.mlx, conf->graph.win,
		conf->graph.img.mlx_img, 0, 0);
	return (0);
}
