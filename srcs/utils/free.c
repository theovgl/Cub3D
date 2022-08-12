/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 15:44:52 by tvogel            #+#    #+#             */
/*   Updated: 2022/08/12 17:17:03 by tvogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_map(t_map *map)
{
	int	y;

	y = 0;
	while (map->map && map->map[y])
		free(map->map[y++]);
	if (map->map)
		free(map->map);
	if (map->path)
		free(map->path);
}

static void	free_textures(t_config *c)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (c->textures[i].path)
		{
			free(c->textures[i].path);
			if (c->textures[i].img.mlx_img != NULL)
			{
				mlx_destroy_image(c->graph.mlx, c->textures[i].img.mlx_img);
				c->textures[i].img.mlx_img = NULL;
			}
		}
		i++;
	}
}

void	free_all(t_config *c)
{
	free_map(&c->map);
	free_textures(c);
	if (c->colors_buf.mlx_img != NULL)
	{
		mlx_destroy_image(c->graph.mlx, c->colors_buf.mlx_img);
		c->colors_buf.mlx_img = NULL;
	}
	if (c->graph.img.mlx_img != NULL)
	{
		mlx_destroy_image(c->graph.mlx, c->graph.img.mlx_img);
		c->graph.img.mlx_img = NULL;
	}
	if (c->graph.win != NULL)
	{
		mlx_destroy_window(c->graph.mlx, c->graph.win);
		c->graph.win = NULL;
	}
	if (c->graph.mlx != NULL)
	{
		mlx_destroy_display(c->graph.mlx);
		free(c->graph.mlx);
		c->graph.mlx = NULL;
	}
}
