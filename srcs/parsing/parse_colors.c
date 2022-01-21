/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 19:00:36 by tvogel            #+#    #+#             */
/*   Updated: 2021/12/30 20:43:36 by tvogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	encode_rgb(unsigned int red, unsigned int green, unsigned int blue)
{
	return (red << 16 | green << 8 | blue);
}

static int	check_color(t_config *c, unsigned int r,
	unsigned int g, unsigned int b)
{
	if (r > 255 || r < 0)
		return (error_handling(c, 1, "Wrong color format"));
	if (g > 255 || g < 0)
		return (error_handling(c, 1, "Wrong color format"));
	if (b > 255 || b < 0)
		return (error_handling(c, 1, "Wrong color format"));
	return (0);
}

static void	save_color(t_config *conf, t_colors *color, char *line)
{
	int	i;
	int	value;

	i = 0;
	while (line[i])
	{
		value = 0;
		if (ft_isdigit(line[i]))
		{
			while (ft_isdigit(line[i]))
				value = value * 10 + line[i++] - 48;
			if (color->r == -1)
				color->r = value;
			else if (color->g == -1)
				color->g = value;
			else if (color->b == -1)
				color->b = value;
		}
		if (line[i])
			i++;
	}
	if (check_color(conf, color->r, color->g, color->b) == 0)
		color->seen = 1;
	color->hex = encode_rgb(color->r, color->g, color->b);
}

int	parse_colors(t_config *conf, char *line)
{
	if (ft_strncmp("F", line, 1) == 0)
		save_color(conf, &conf->floor, line);
	if (ft_strncmp("C", line, 1) == 0)
		save_color(conf, &conf->ceiling, line);
	return (0);
}
