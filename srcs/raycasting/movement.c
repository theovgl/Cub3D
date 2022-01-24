/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:30:22 by tvogel            #+#    #+#             */
/*   Updated: 2022/01/24 10:21:15 by tvogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_player(int keysym, t_config *conf)
{
	if (keysym == XK_w)
	{
		if (conf->map.map[conf->player.y - 1][conf->player.x] != '1')
			conf->player.y -= 1;
	}
	else if (keysym == XK_a)
	{
		if (conf->map.map[conf->player.y][conf->player.x - 1] != '1')
			conf->player.x -= 1;
	}
	else if (keysym == XK_s)
	{
		if (conf->map.map[conf->player.y + 1][conf->player.x] != '1')
			conf->player.y += 1;
	}
	else if (keysym == XK_d)
	{
		if (conf->map.map[conf->player.y][conf->player.x + 1] != '1')
			conf->player.x += 1;
	}
	printf("Player X: %i, Player Y: %i\n", conf->player.x, conf->player.y);
}
