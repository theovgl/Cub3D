/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:37:59 by tvogel            #+#    #+#             */
/*   Updated: 2022/02/06 00:38:53 by tvogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H
# include "cub3d.h"

int		start(t_config *conf, t_graph *g);
void	cast_rays(t_config *c, t_player *p);
int		render(t_config *conf);

float	normalize_angle(float angle);
void	check_orientation(t_ray *r, float angle);

void	check_vertical(t_config *c, t_ray *r);
void	check_horizontal(t_config *c, t_ray *r);
void	get_intercept(t_config *c, t_ray *r, int vertical);
void	get_delta(t_config *c, t_ray *r, int vertical);
int		check_for_wall(t_config *c, float x, float y);

#endif
