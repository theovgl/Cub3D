/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:26:18 by tvogel            #+#    #+#             */
/*   Updated: 2022/02/12 18:06:29 by tvogel           ###   ########.fr       */
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
	c->tile_size = SCR_WIDTH / c->map.map_width;
	player->turn_dir = 0;
	player->walk_dir = 0;
	player->walk_speed = 2;
	player->rotation_ang = M_PI / 2;
	player->turn_speed = 5 * (M_PI / 180);
	player->width = c->tile_size / 2;
	player->height = c->tile_size / 2;
	player->fov = 60 * (M_PI / 180);
	player->x *= c->tile_size;
	player->y *= c->tile_size;
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
