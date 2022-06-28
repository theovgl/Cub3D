/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnaud <arnaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 17:50:05 by tvogel            #+#    #+#             */
/*   Updated: 2022/06/28 16:22:38 by arnaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_map(t_config *conf, char *line, int print)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'N' && line[i] != 'S'
			&& line[i] != 'E' && line[i] != 'W' && (!ft_isspace(line[i])))
		{
			if (print)
				return (error_handling(conf, 1, "Bad char. in map"));
			else
				return (1);
		}
		i++;
	}
	return (0);
}

static int	count_map(t_config *conf, char *line)
{
	if (is_map(conf, line, 1) == 0)
	{
		if ((int)ft_strlen(line) > conf->map.map_width)
			conf->map.map_width = ft_strlen(line);
		conf->map.map_height++;
	}
	return (0);
}

int	parse_map(t_config *conf)
{
	char	*line;

	line = NULL;
	while (get_next_line(conf->map_fd, &line))
	{
		count_map(conf, line);
		free(line);
		if (conf->error)
			return (1);
	}
	free(line);
	return (0);
}
