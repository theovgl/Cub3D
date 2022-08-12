/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiju-du <abiju-du@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:26:18 by tvogel            #+#    #+#             */
/*   Updated: 2022/08/12 14:16:33 by abiju-du         ###   ########.fr       */
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

static void	player_init_dir(t_player *player)
{
	if (player->dir_init == 'E')
	{
		player->dir_y = 1;
		player->plane_x = -0.66 * sin(4.71);
		player->plane_y = 0.66 * cos(4.71);
	}
	else if (player->dir_init == 'W')
	{
		player->dir_y = -1;
		player->plane_x = -0.66;
		player->plane_y = 0;
	}
	else if (player->dir_init == 'N')
	{
		player->dir_x = -1;
		player->plane_x = 0;
		player->plane_y = 0.66;
	}
	else if (player->dir_init == 'S')
	{
		player->dir_x = 1;
		player->plane_x = -0.66 * sin(3.14);
		player->plane_y = 0.66 * cos(3.14);
	}
}

static void	init_raycast(t_player *player)
{
	player->x += 0.5;
	player->y += 0.5;
	player->dir_x = 0;
	player->dir_y = 0;
	player->strafe_speed = 0;
	player->walk_speed = 0;
	player->rotation_speed = 0;
	player_init_dir(player);
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
	if (load_textures(conf))
		return (1);
	init_raycast(&conf->player);
	init_colors_buffer(conf);
	open_windows(g);
	mlx_loop_hook(g->mlx, &render, conf);
	mlx_hook(g->win, ClientMessage, StructureNotifyMask,
		&close_window, g);
	mlx_hook(g->win, KeyPress, KeyPressMask, &keydown, conf);
	mlx_hook(g->win, KeyRelease, KeyReleaseMask, &keyup, conf);
	mlx_loop(g->mlx);
	return (0);
}
