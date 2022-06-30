/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:05:27 by tvogel            #+#    #+#             */
/*   Updated: 2022/06/28 17:37:35 by tvogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

static void	update(t_config *conf)
{
	clear_buffer(conf);
	cast_rays(conf, &conf->player);
	draw_walls(conf, conf->rays);
}

int	render(t_config *conf)
{
	update(conf);
	mlx_put_image_to_window(conf->graph.mlx, conf->graph.win,
		conf->colors_buf.mlx_img, 0, 0);
	return (0);
}
