/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_settings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:50:43 by tvogel            #+#    #+#             */
/*   Updated: 2022/08/12 18:41:22 by tvogel           ###   ########.fr       */
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
		if (!ft_isspace(line[i]) && line[i] != '.')
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
	int	i;

	i = 0;
	if (line[0] == '\n' || line[0] == '\0')
		return (0);
	while (ft_isspace(line[i]))
		i++;
	if (ft_strncmp("NO", &line[i], 2) == 0)
		save_texture(conf, &line[i], &conf->textures[0]);
	else if (ft_strncmp("SO", &line[i], 2) == 0)
		save_texture(conf, &line[i], &conf->textures[1]);
	else if (ft_strncmp("WE", &line[i], 2) == 0)
		save_texture(conf, &line[i], &conf->textures[2]);
	else if (ft_strncmp("EA", &line[i], 2) == 0)
		save_texture(conf, &line[i], &conf->textures[3]);
	return (0);
}

int	parse_settings(t_config *conf)
{
	char	*line;

	line = NULL;
	conf->map.map_begin = 0;
	while (get_next_line(conf->map_fd, &line, 0)
		&& settings_checker(conf) == 1)
	{
		parse_textures(conf, line);
		parse_colors(conf, line);
		free(line);
		conf->map.map_begin++;
		if (conf->error)
		{
			get_next_line(0, NULL, 1);
			line = NULL;
			break ;
		}
	}
	free(line);
	if (settings_checker(conf) == 1)
	{
		close(conf->map_fd);
		return (error_handling(conf, 1, "Missing settings in .cub file"));
	}
	parse_map(conf);
	close(conf->map_fd);
	if (conf->error == 1)
		return (1);
	return (0);
}
