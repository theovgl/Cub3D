/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:30:22 by tvogel            #+#    #+#             */
/*   Updated: 2022/01/27 11:06:24 by tvogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// printf("Player X: %f, Player Y: %f\n", conf->player.x, conf->player.y);

void	move_player(int keysym, t_config *conf)
{
	int	pos_x;
	int	pos_y;

	pos_x = floorf(conf->player.x);
	pos_y = floorf(conf->player.y);
	if (keysym == XK_w
		&& conf->map.map[pos_y - 1][pos_x] != '1')
		conf->player.y -= 1;
	else if (keysym == XK_a
		&& conf->map.map[pos_y][pos_x - 1] != '1')
		conf->player.x -= 1;
	else if (keysym == XK_s
		&& conf->map.map[pos_y + 1][pos_x] != '1')
		conf->player.y += 1;
	else if (keysym == XK_d
		&& conf->map.map[pos_y][pos_x + 1] != '1')
		conf->player.x += 1;
}
