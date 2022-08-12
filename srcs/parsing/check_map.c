/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 10:25:41 by tvogel            #+#    #+#             */
/*   Updated: 2022/08/12 17:58:18 by tvogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_player(t_config *c, char *line, int y)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'N' || line[i] == 'S'
			|| line[i] == 'E' || line[i] == 'W')
		{
			c->player.dir_init = line[i];
			c->player.x = i;
			c->player.y = y;
			c->player.seen++;
			c->map.map[y][i] = '0';
			return (0);
		}
		i++;
	}
	if (y == c->map.map_height - 1 && c->player.seen == 0)
		return (error_handling(c, 1, "Missing player position"));
	if (y == c->map.map_height && c->player.seen > 1)
		return (error_handling(c, 1, "More than one player position"));
	return (0);
}

int	check_map(t_config *conf, t_map map)
{
	int	i;

	i = 0;
	conf->player.seen = 0;
	if (map.map_width < 2 || map.map_height < 2)
	{
		return (error_handling(conf, 1, "Missing map or wrong map format"));
	}
	while (map.map[i])
	{
		if (check_player(conf, map.map[i], i) == 1)
			return (1);
		i++;
	}
	if (floodfill(conf, map))
		return (error_handling(conf, 1, "Floodfill found a map leak"));
	return (0);
}
