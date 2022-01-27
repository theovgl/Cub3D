/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 10:38:45 by tvogel            #+#    #+#             */
/*   Updated: 2022/01/27 11:03:13 by tvogel           ###   ########.fr       */
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

void	draw_line(t_graph g, t_point p0, t_point p1, int color);

#endif
