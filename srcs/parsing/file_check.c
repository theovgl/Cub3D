/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:04:20 by tvogel            #+#    #+#             */
/*   Updated: 2022/08/12 18:23:37 by tvogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_extension(t_config *c, char *path, char *to_check, int pos)
{
	int	i;

	i = 0;
	while (path[pos] || to_check[i])
	{
		if (path[pos] != to_check[i])
			return (error_handling(c, 1, "Bad extension"));
		i++;
		pos++;
	}
	return (0);
}

int	check_file(t_config *conf, const char *file_path)
{
	int	i;
	int	size;
	int	fd;

	size = ft_strlen(file_path);
	i = size - 4;
	if (check_extension(conf, (char *)file_path, ".cub", i))
		return (1);
	fd = open(file_path, O_RDWR);
	if (fd == -1)
	{
		perror(file_path);
		return (1);
	}
	conf->map.path = ft_strdup(file_path);
	conf->map_fd = fd;
	return (0);
}
