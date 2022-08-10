/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:05:27 by tvogel            #+#    #+#             */
/*   Updated: 2022/08/10 15:46:59 by tvogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

static void	move(t_config *conf)
{
	shift(&conf->player, &conf->map, conf->player.right);
	move_forward(&conf->player, &conf->map);
	rotate(&conf->player);
}

int	render(t_config *conf)
{
	clear_buffer(conf);
	move(conf);
	cast_rays(conf, &conf->player);
	draw_walls(conf);
	mlx_put_image_to_window(conf->graph.mlx, conf->graph.win,
		conf->colors_buf.mlx_img, 0, 0);
	return (0);
}
