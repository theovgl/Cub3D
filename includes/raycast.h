/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 15:37:59 by tvogel            #+#    #+#             */
/*   Updated: 2022/01/27 10:40:25 by tvogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H
# include "cub3d.h"

typedef struct s_raycast
{
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_raycast;

#endif
