/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 17:33:06 by tvogel            #+#    #+#             */
/*   Updated: 2021/12/30 21:41:30 by tvogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	settings_checker(t_config *conf)
{
	t_textures	current;
	int			i;

	i = 0;
	while (i < 4)
	{
		current = conf->textures[i];
		if (conf->floor.seen == 0 || conf->ceiling.seen == 0)
			return (1);
		if (current.path == NULL)
			return (1);
		i++;
	}
	return (0);
}
