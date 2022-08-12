/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:37:59 by tvogel            #+#    #+#             */
/*   Updated: 2022/08/12 14:16:58 by tvogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H
# include "cub3d.h"

int		start(t_config *conf, t_graph *g);
void	cast_rays(t_config *c, t_player *p);
int		load_textures(t_config *c);
void	calculate_textures(t_config *c, t_player *p, t_ray *r, int x);
int		render(t_config *conf);
void	draw_walls(t_config *c);
void	shift(t_player *p, t_map *m);

#endif
