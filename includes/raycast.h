/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiju-du <abiju-du@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:37:59 by tvogel            #+#    #+#             */
/*   Updated: 2022/07/15 19:08:06 by abiju-du         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H
# include "cub3d.h"

int		start(t_config *conf, t_graph *g);
void	cast_rays(t_config *c, t_player *p);
int		render(t_config *conf);
void	shift(t_player *p, t_map *m, int right);

#endif
