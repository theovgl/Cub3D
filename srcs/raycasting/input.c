/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:42:10 by tvogel            #+#    #+#             */
/*   Updated: 2022/07/27 16:18:05 by tvogel           ###   ########.fr       */
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
		conf->player.walk_speed = 0.1;
	if (keysym == XK_s)
		conf->player.walk_speed = -0.1;
	if (keysym == XK_d)
		shift(&conf->player, &conf->map, 1);
	if (keysym == XK_a)
		shift(&conf->player, &conf->map, -1);
	if (keysym == XK_Right)
		conf->player.rotation_speed = 0.07;
	if (keysym == XK_Left)
		conf->player.rotation_speed = -0.07;
	return (0);
}

int	keyup(int keysym, t_config *conf)
{
	if (keysym == XK_w || keysym == XK_z)
		conf->player.walk_speed = 0;
	if (keysym == XK_s)
		conf->player.walk_speed = 0;
	if (keysym == XK_Right)
		conf->player.rotation_speed = 0;
	if (keysym == XK_Left)
		conf->player.rotation_speed = 0;
	if (keysym == XK_Shift_L)
		conf->player.walk_speed -= 0.1;
	return (0);
}
