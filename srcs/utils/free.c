/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 15:44:52 by tvogel            #+#    #+#             */
/*   Updated: 2022/07/28 14:26:23 by tvogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_map(t_map *map)
{
	int	y;

	y = 0;
	while (map->map[y])
		free(map->map[y++]);
	if (map->map)
		free(map->map);
	if (map->path)
		free(map->path);
}

void	free_textures(t_config *c)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (c->textures[i].path)
			free(c->textures[i].path);
		i++;
	}
}

void	free_all(t_config *c)
{
	free_map(&c->map);
	free_textures(c);
	if (c->graph.img.mlx_img)
		free(c->graph.mlx);
}
