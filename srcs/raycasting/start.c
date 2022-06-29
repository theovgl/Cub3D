/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:26:18 by tvogel            #+#    #+#             */
/*   Updated: 2022/06/24 16:25:59 by tvogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

static void	init_mlx(t_graph *g)
{
	g->mlx = mlx_init();
	g->img.mlx_img = mlx_new_image(g->mlx, SCR_WIDTH, SCR_HEIGHT);
	g->img.addr = mlx_get_data_addr(g->img.mlx_img, &g->img.bpp,
			&g->img.line_len, &g->img.endian);
}

static void	init_raycast(t_config *c, t_player *player)
{
	player->walk_speed = 0.05;
	player->rotation_speed = 0.02;
	player->dir_x = -1;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = 0.66;
}

int	init_colors_buffer(t_config *c)
{
	c->colors_buf.mlx_img = mlx_new_image(c->graph.mlx, SCR_WIDTH, SCR_HEIGHT);
	c->colors_buf.addr = mlx_get_data_addr(c->colors_buf.mlx_img,
			&c->colors_buf.bpp, &c->colors_buf.line_len, &c->colors_buf.endian);
	return (0);
}

int	start(t_config *conf, t_graph *g)
{
	init_mlx(g);
	init_raycast(conf, &conf->player);
	init_colors_buffer(conf);
	open_windows(g);
	mlx_loop_hook(g->mlx, &render, conf);
	mlx_hook(g->win, ClientMessage, StructureNotifyMask,
		&close_window, g);
	mlx_hook(g->win, KeyPress, KeyPressMask, &keydown, conf);
	mlx_hook(g->win, KeyRelease, KeyReleaseMask, &keyup, conf);
	mlx_loop(g->mlx);
	mlx_destroy_window(g->mlx, g->win);
	mlx_destroy_display(g->mlx);
	free(g->mlx);
	return (0);
}
