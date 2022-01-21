/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:26:18 by tvogel            #+#    #+#             */
/*   Updated: 2022/01/21 17:11:44 by tvogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_mlx(t_graph *g)
{
	g->mlx = mlx_init();
	g->img.mlx_img = mlx_new_image(g->mlx, SCR_WIDTH, SCR_HEIGHT);
	g->img.addr = mlx_get_data_addr(g->img.mlx_img, &g->img.bpp,
			&g->img.line_len, &g->img.endian);
}

int	start(t_config *conf, t_graph *g)
{
	init_mlx(g);
	open_windows(g);
	draw_map(conf, g, &conf->map);
	mlx_put_image_to_window(g->mlx, g->win, g->img.mlx_img, 1, 1);
	mlx_hook(g->win, ClientMessage, StructureNotifyMask,
		&close_window, g);
	mlx_key_hook(g->win, &handle_input, g);
	mlx_loop_hook(g->mlx, &my_mlx_loop_hook, g);
	mlx_loop(g->mlx);
	mlx_destroy_display(g->mlx);
	free(g->mlx);
	return (0);
}
