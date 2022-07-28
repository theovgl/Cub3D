/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 10:38:45 by tvogel            #+#    #+#             */
/*   Updated: 2022/07/28 14:12:19 by tvogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H
# include "cub3d.h"

typedef struct s_line
{
	int	x_start;
	int	y_start;
	int	x_end;
	int	y_end;
}	t_line;

typedef struct s_point
{
	float	x;
	float	y;
}	t_point;

typedef struct s_rect
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	color;
}	t_rect;

void	draw_line(t_graph g, t_point p0, t_point p1, int color);
void	render_rect(t_graph g, t_rect rect);

void	draw_map(t_config *conf);
void	draw_player(t_config *conf, t_player *player);
void	draw_walls(t_config *c);

int		load_textures(t_config *c);
void	calculate_textures(t_config *c, t_player *p, t_ray *r, int x);

#endif
