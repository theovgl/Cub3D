/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:42:10 by tvogel            #+#    #+#             */
/*   Updated: 2022/07/31 20:13:27 by tvogel           ###   ########.fr       */
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
		conf->player.walk_speed = 0.08;
	if (keysym == XK_s)
		conf->player.walk_speed = -0.08;
	if (keysym == XK_d)
	{
		// shift(&conf->player, &conf->map, 1);
		conf->player.strafe_speed = 0.08;
		conf->player.right = 1;
	}
	if (keysym == XK_a)
	{
		conf->player.left = 1;
		conf->player.strafe_speed = -0.08;

	}
	if (keysym == XK_Right)
		conf->player.rotation_speed = 0.05;
	if (keysym == XK_Left)
		conf->player.rotation_speed = -0.05;
	return (0);
}

int	keyup(int keysym, t_config *conf)
{
	if (keysym == XK_w || keysym == XK_z)
		conf->player.walk_speed = 0;
	if (keysym == XK_s)
		conf->player.walk_speed = 0;
	if (keysym == XK_d)
	{
		conf->player.strafe_speed = 0;
		conf->player.right = 0;
	}
	if (keysym == XK_a)
	{
		conf->player.strafe_speed = 0;
		conf->player.left = 0;
	}
	if (keysym == XK_Right)
		conf->player.rotation_speed = 0;
	if (keysym == XK_Left)
		conf->player.rotation_speed = 0;
	return (0);
}
