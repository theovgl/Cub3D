/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:38:11 by tvogel            #+#    #+#             */
/*   Updated: 2022/01/21 16:39:40 by tvogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	my_mlx_loop_hook(void)
{
	return (0);
}

void	my_mlx_pixel_put(t_graph graph, int x, int y, int color)
{
	char	*dst;

	dst = graph.img.addr + (y * graph.img.line_len + x * (graph.img.bpp / 8));
	*(unsigned int *)dst = color;
}

int	close_window(t_graph *g)
{
	mlx_destroy_window(g->mlx, g->win);
	printf("👋\n");
	return (0);
}

int	open_windows(t_graph *graph)
{
	if (graph->mlx == NULL)
		return (1);
	graph->win = mlx_new_window(graph->mlx, SCR_WIDTH, SCR_HEIGHT, "cub3d");
	if (graph->win == NULL)
	{
		free(graph->win);
		return (1);
	}
	return (0);
}