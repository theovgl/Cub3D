/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:26:18 by tvogel            #+#    #+#             */
/*   Updated: 2022/01/27 11:01:23 by tvogel           ###   ########.fr       */
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

static void	init_raycast(t_player *player)
{
	player->turn_dir = 0;
	player->walk_dir = 0;
	player->walk_speed = 100;
	player->rotation_ang = M_PI * 2;
	player->turn_speed = 45 * (M_PI / 180);
}

int	start(t_config *conf, t_graph *g)
{
	init_mlx(g);
	init_raycast(&conf->player);
	open_windows(g);
	mlx_loop_hook(g->mlx, &render, conf);
	mlx_hook(g->win, ClientMessage, StructureNotifyMask,
		&close_window, g);
	mlx_key_hook(g->win, &handle_input, conf);
	mlx_loop(g->mlx);
	mlx_destroy_display(g->mlx);
	free(g->mlx);
	return (0);
}