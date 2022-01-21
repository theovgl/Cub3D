/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 17:12:22 by tvogel            #+#    #+#             */
/*   Updated: 2022/01/21 14:15:31 by tvogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_map(t_map map)
{
	int	i;

	i = 0;
	while (map.map[i])
	{
		printf("%s\n", map.map[i]);
		i++;
	}
}

void	print_player(t_config *conf)
{
	printf("\nPlayer X: %i, Player Y: %i\n", conf->player.x, conf->player.y);
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
