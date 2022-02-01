/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:05:27 by tvogel            #+#    #+#             */
/*   Updated: 2022/02/01 22:24:01 by tvogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

static void	update(t_config *conf)
{
	move_player(conf, &conf->player, &conf->map);
	cast_rays(conf, &conf->player);
}

static void	draw_rays(t_config *c)
{
	t_ray	ray;
	int		i;

	i = 0;
	while (i < 1)
	{
		ray = c->rays[i];
		draw_line(c->graph, (t_point){
			c->player.x + (c->tile_size / 2) / 2,
			c->player.y + (c->tile_size / 2) / 2
		}, (t_point){
			ray.wallHitX, ray.wallHitY
		}, 0x00FFA701);
		i++;
	}

}

int	render(t_config *conf)
{
	update(conf);
	draw_map(conf);
	draw_player(conf, &conf->player);
	draw_rays(conf);
	mlx_put_image_to_window(conf->graph.mlx, conf->graph.win,
		conf->graph.img.mlx_img, 0, 0);
	return (0);
}
