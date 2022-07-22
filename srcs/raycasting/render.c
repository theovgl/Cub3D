/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnaud <arnaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:05:27 by tvogel            #+#    #+#             */
/*   Updated: 2022/07/15 18:00:52 by tvogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

int	render(t_config *conf)
{
	clear_buffer(conf);
	cast_rays(conf, &conf->player);
	draw_walls(conf, conf->rays);
	mlx_put_image_to_window(conf->graph.mlx, conf->graph.win,
		conf->colors_buf.mlx_img, 0, 0);
	return (0);
}
