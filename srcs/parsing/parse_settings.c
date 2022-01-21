/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_settings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:50:43 by tvogel            #+#    #+#             */
/*   Updated: 2022/01/04 18:40:43 by tvogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	save_texture(t_config *conf, char *line, t_textures *texture)
{
	int	i;
	int	j;
	int	size;

	i = 2;
	while (line[i] != '.' && line[i])
	{
		if (line[i] != ' ' && line[i] != '.')
			return (error_handling(conf, 1, "Wrong texture path"));
		i++;
	}
	j = 0;
	size = ft_strlen(line) - i;
	texture->path = malloc(sizeof(char *) * size + 1);
	if (!texture->path)
		error_handling(conf, 1, "Malloc failed");
	while (line[i])
		texture->path[j++] = line[i++];
	texture->path[j] = '\0';
	texture->saved = 1;
	return (0);
}

static int	parse_textures(t_config *conf, char *line)
{
	if (line[0] == '\n' || line[0] == '\0')
		return (0);
	if (ft_strncmp("NO", line, 2) == 0)
		save_texture(conf, line, &conf->textures[0]);
	else if (ft_strncmp("SO", line, 2) == 0)
		save_texture(conf, line, &conf->textures[1]);
	else if (ft_strncmp("WE", line, 2) == 0)
		save_texture(conf, line, &conf->textures[2]);
	else if (ft_strncmp("EA", line, 2) == 0)
		save_texture(conf, line, &conf->textures[3]);
	return (0);
}

int	parse_settings(t_config *conf)
{
	char	*line;

	line = NULL;
	conf->map.map_begin = 0;
	while (get_next_line(conf->map_fd, &line) && !conf->error
		&& settings_checker(conf) == 1)
	{
		parse_textures(conf, line);
		parse_colors(conf, line);
		free(line);
		conf->map.map_begin++;
	}
	free(line);
	if (settings_checker(conf) == 1)
		return (error_handling(conf, 1, "Missing settings in .cub file"));
	parse_map(conf);
	close(conf->map_fd);
	if (conf->error == 1)
		return (1);
	return (0);
}
