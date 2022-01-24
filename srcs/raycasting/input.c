/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:42:10 by tvogel            #+#    #+#             */
/*   Updated: 2022/01/24 10:20:45 by tvogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_input(int key, t_config *conf)
{
	if (key == XK_Escape)
	{
		mlx_loop_end(conf->graph.mlx);
		close_window(&conf->graph);
	}
	else if (key == XK_w || key == XK_a || key == XK_s || key == XK_d)
	{
		move_player(key, conf);
	}
	return (0);
}
