/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 10:36:42 by tvogel            #+#    #+#             */
/*   Updated: 2022/01/27 11:09:36 by tvogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

void	swap_point(t_point *p0, t_point *p1)
{
	t_point	temp;

	temp = *p1;
	p1 = p0;
	*p0 = temp;
}

static void	draw_line_x(t_graph g, t_point p0, t_point p1, int c)
{
	float	b;
	int		x;
	float	y;
	float	slope;

	if (p0.x > p1.x)
		swap_point(&p0, &p1);
	slope = (p1.y - p0.y) / (p1.x - p0.x);
	b = p0.y - slope * p0.x;
	x = (int)p0.x;
	while (x < p1.x)
	{
		y = slope * (float)x + b;
		my_mlx_pixel_put(g, x++, (int)y, c);
	}
}

static void	draw_line_y(t_graph g, t_point p0, t_point p1, int c)
{
	float	b;
	int		y;
	float	x;
	float	slope;

	if (p0.y > p1.y)
		swap_point(&p0, &p1);
	slope = (p1.x - p0.x) / (p1.y - p0.y);
	b = p0.x - slope * p0.y;
	y = (int)p0.y;
	while (y < (int)p1.y)
	{
		x = slope * (float)y + b;
		my_mlx_pixel_put(g, (int)x, y, c);
		y++;
	}
}

void	draw_line(t_graph g, t_point p0, t_point p1, int color)
{
	float	slope;

	slope = 0;
	if (p1.x != p0.x && fabs(slope) <= 1.0)
		draw_line_x(g, p0, p1, color);
	else
		draw_line_y(g, p0, p1, color);
}
