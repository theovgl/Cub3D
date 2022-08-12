/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiju-du <abiju-du@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 22:14:06 by tvogel            #+#    #+#             */
/*   Updated: 2022/08/11 14:53:36 by abiju-du         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_textures(t_config *conf)
{
	t_textures	*current;
	int			i;

	i = 0;
	while (i < 4)
	{
		current = &conf->textures[i];
		current->path = NULL;
		current->saved = 0;
		i++;
	}
}

static void	init_map(t_config *conf)
{
	conf->map.map_height = 0;
	conf->map.map_width = 0;
}

static void	init_colors(t_config *conf)
{
	conf->floor.seen = 0;
	conf->floor.r = -1;
	conf->floor.g = -1;
	conf->floor.b = -1;
	conf->floor.hex = 0;
	conf->ceiling.seen = 0;
	conf->ceiling.r = -1;
	conf->ceiling.g = -1;
	conf->ceiling.b = -1;
	conf->ceiling.hex = 0;
}

int	init(t_config *conf)
{
	conf->error = 0;
	init_textures(conf);
	init_colors(conf);
	init_map(conf);
	return (0);
}
