/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnaud <arnaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 17:12:22 by tvogel            #+#    #+#             */
/*   Updated: 2022/06/28 14:14:50 by arnaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_map(t_map map)
{
	int	i;
	int	j;

	i = 0;
	while (map.map[i])
	{
		j = 0;
		while (map.map[i][j])
		{
			if (map.map[i][j] == '1')
				printf("\033[0;31m%c", map.map[i][j]);
			else if (map.map[i][j] == '0' || map.map[i][j] == 'x')
				printf("\033[0;37m%c", map.map[i][j]);
			else if (map.map[i][j] == 'N' || map.map[i][j] == 'E'
				|| map.map[i][j] == 'W' || map.map[i][j] == 'S')
				printf("\033[1;33m%c", map.map[i][j]);
			else if (map.map[i][j] == '\t')
				printf("    ");
			else
				printf(" ");
			j++;
		}
		printf("\033[0m\n");
		i++;
	}
}

void	print_player(t_config *conf)
{
	printf("\nPlayer X: %f, Player Y: %f\n", conf->player.x, conf->player.y);
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
	print_player(conf);
	return (0);
}
