/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 17:12:22 by tvogel            #+#    #+#             */
/*   Updated: 2022/08/12 19:04:02 by tvogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_map(t_map map)
{
	int	x;
	int	y;

	y = 0;
	while (map.map[y])
	{
		x = 0;
		while (map.map[y][x])
		{
			if (map.map[y][x] == '1')
				printf("\033[0;31m%c", map.map[y][x]);
			else if (map.map[y][x] == '0' || map.map[y][x] == 'x')
				printf("\033[0;37m%c", map.map[y][x]);
			else if (map.map[y][x] == 'N' || map.map[y][x] == 'E'
				|| map.map[y][x] == 'W' || map.map[y][x] == 'S')
				printf("\033[1;33m%c", map.map[y][x]);
			else if (map.map[y][x] == '\t' || map.map[y][x] == ' ')
				printf("%c", map.map[y][x]);
			x++;
		}
		printf("\033[0m\n");
		y++;
	}
}

int	parsing(t_config *conf, const char *av[])
{
	if (check_file(conf, av[1]) == 1)
		return (1);
	if (parse_settings(conf) == 1)
		return (1);
	if (save_map(conf) == 1)
		return (1);
	if (check_map(conf, conf->map) == 1)
		return (1);
	print_map(conf->map);
	return (0);
}
