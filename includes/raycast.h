/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:37:59 by tvogel            #+#    #+#             */
/*   Updated: 2022/06/23 18:58:50 by tvogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H
# include "cub3d.h"

int		start(t_config *conf, t_graph *g);
void	cast_rays(t_config *c, t_player *p);
int		render(t_config *conf);

#endif
