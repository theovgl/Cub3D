/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:42:10 by tvogel            #+#    #+#             */
/*   Updated: 2022/06/24 15:54:27 by tvogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	keydown(int keysym, t_config *conf)
{
	if (keysym == XK_Escape)
	{
		close_window(&conf->graph);
		printf("Escape\n");
	}
	if (keysym == XK_w || keysym == XK_z)
		move_forward(&conf->player, &conf->map);
	if (keysym == XK_s)
		move_backward(&conf->player, &conf->map);
	if (keysym == XK_d)
		rotate(&conf->player, 1);
	if (keysym == XK_q)
		rotate(&conf->player, 0);
	if (keysym == 65505)
		conf->player.walk_speed += 0.8;
	return (0);
}

int	keyup(int keysym, t_config *conf)
{
	if (keysym == XK_w)
		conf->player.walk_dir = 0;
	if (keysym == XK_s)
		conf->player.walk_dir = 0;
	if (keysym == XK_Right)
		conf->player.turn_dir = 0;
	if (keysym == XK_Left)
		conf->player.turn_dir = 0;
	if (keysym == 65505)
		conf->player.walk_speed -= 0.8;
	return (0);
}
