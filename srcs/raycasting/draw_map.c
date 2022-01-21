/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:11:07 by tvogel            #+#    #+#             */
/*   Updated: 2022/01/21 17:29:25 by tvogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_square(t_graph g, int x, int y, char type)
{
	int	i;
	int	j;
	int	size;

	i = y;
	size = 100;
	printf("%c\n", type);
	while (i < y + size)
	{
		j = x;
		while (j < x + size)
		{
			if (type == '1')
				my_mlx_pixel_put(g, j, i, 0x00AA4A44);
			else if (type == '0')
				my_mlx_pixel_put(g, j, i, 0x00FFFFFF);
			else
				my_mlx_pixel_put(g, j, i, 0x00FFC000);
			j++;
		}
		i++;
	}
}

int	draw_map(t_config *conf, t_graph *g, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			draw_square(*g, j, i, map->map[i][j]);
			j++;
		}
		i++;
	}
	return (0);
}
