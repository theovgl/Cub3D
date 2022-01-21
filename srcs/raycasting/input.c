/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:42:10 by tvogel            #+#    #+#             */
/*   Updated: 2022/01/21 16:00:53 by tvogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_input(int key, t_graph *graph)
{
	if (key == XK_Escape)
	{
		mlx_loop_end(graph->mlx);
		close_window(graph);
	}
	return (0);
}
