/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 10:25:41 by tvogel            #+#    #+#             */
/*   Updated: 2022/01/24 10:05:11 by tvogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_wall(t_map map, char *line, int pos)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (pos == 0 || pos == (map.map_height - 1))
		{
			if (line[i] != '1')
				return (1);
		}
		else
		{
			if (i == 0 && line[i] != '1')
				return (1);
			else if (i == (map.map_width - 1) && line[i] != '1')
				return (1);
		}
		i++;
	}
	return (0);
}

static int	check_player(t_config *c, char *line, int y)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'N' || line[i] == 'S'
			|| line[i] == 'E' || line[i] == 'W')
		{
			c->player.x = i;
			c->player.y = y;
			c->player.seen++;
			return (0);
		}
		i++;
	}
	if (y == c->map.map_height && c->player.seen == 0)
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
	while (map.map[i])
	{
		if (check_wall(map, map.map[i], i))
			return (error_handling(conf, 1, "Map isn't closed"));
		if (check_player(conf, map.map[i], i) == 1)
			return (1);
		i++;
	}
	return (0);
}
