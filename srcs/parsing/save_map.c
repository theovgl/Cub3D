/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:49:34 by tvogel            #+#    #+#             */
/*   Updated: 2022/01/30 18:58:19 by tvogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	save_line(t_map *map, char *line, int pos)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	map->map[pos] = malloc(sizeof(char) * (map->map_width + 1));
	while (j < map->map_width)
	{
		if (line[i] == '0' || line[i] == '1' || line[i] == 'N'
			|| line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
			map->map[pos][j] = line[i];
		// else if (line[i] == ' ')
		// 	map->map[pos][j] = '1';
		// else
		// 	map->map[pos][j] = '1';
		if (line[i])
			i++;
		j++;
	}
	map->map[pos][j] = '\0';
	return (0);
}

int	save_map(t_config *conf)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	conf->map_fd = open(conf->map.path, O_RDONLY);
	conf->map.map = malloc(sizeof(char *) * (conf->map.map_height + 1));
	if (!conf->map.map)
		return (error_handling(conf, 1, "Malloc failed"));
	while (get_next_line(conf->map_fd, &line))
	{
		if (is_map(conf, line, 0) == 0 && i > conf->map.map_begin)
			save_line(&conf->map, line, j++);
		i++;
		free(line);
	}
	conf->map.map[j++] = NULL;
	free(line);
	return (0);
}
