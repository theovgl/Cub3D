/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiju-du <abiju-du@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 19:00:36 by tvogel            #+#    #+#             */
/*   Updated: 2022/08/12 14:16:14 by abiju-du         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	to_rgb(unsigned int red, unsigned int green, unsigned int blue)
{
	return (red << 16 | green << 8 | blue);
}

static int	check_color(t_config *c, unsigned int r,
	unsigned int g, unsigned int b)
{
	if (r > 255)
		return (error_handling(c, 1, "Wrong color format"));
	if (g > 255)
		return (error_handling(c, 1, "Wrong color format"));
	if (b > 255)
		return (error_handling(c, 1, "Wrong color format"));
	return (0);
}

static int	save_color(t_config *conf, t_colors *color, char *line)
{
	int	i;
	int	value;

	i = 1;
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
		if (ft_isspace(line[i]) || (line[i] == ',' && color->b == -1))
			i++;
		else if (line[i])
			return (error_handling(conf, 1, "Wrong color format"));
	}
	return (check_color(conf, color->r, color->g, color->b));
}

int	parse_colors(t_config *c, char *line)
{
	int	i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	if (ft_strncmp("F", &line[i], 1) == 0)
	{
		if (save_color(c, &c->floor, &line[i]))
			return (1);
		c->floor.seen = 1;
		c->floor.hex = to_rgb(c->floor.r, c->floor.g, c->floor.b);
	}
	if (ft_strncmp("C", &line[i], 1) == 0)
	{
		if (save_color(c, &c->ceiling, &line[i]))
			return (1);
		c->ceiling.seen = 1;
		c->ceiling.hex = to_rgb(c->ceiling.r, c->ceiling.g, c->ceiling.b);
	}
	return (0);
}
