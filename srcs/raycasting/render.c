/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnaud <arnaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:05:27 by tvogel            #+#    #+#             */
/*   Updated: 2022/06/28 16:14:52 by arnaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

static void	update(t_config *conf)
{
	clear_buffer(conf);
	move_player(conf, &conf->player, &conf->map);
	cast_rays(conf, &conf->player);
	generate_walls(conf, conf->rays);
}

static void	draw_rays(t_config *c)
{
	t_ray	ray;
	int		i;

	i = 0;
	while (i < SCR_WIDTH)
	{
		ray = c->rays[i];
		draw_line(c->graph, (t_point){
			c->player.x,
			c->player.y
		}, (t_point){
			ray.x,
			ray.y
		}, 0x00FFA701);
		i++;
	}
}

int	render(t_config *conf)
{
	update(conf);
	mlx_put_image_to_window(conf->graph.mlx, conf->graph.win,
		conf->colors_buf.mlx_img, 0, 0);
	return (0);
}
