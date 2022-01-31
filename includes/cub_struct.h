/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 10:53:03 by tvogel            #+#    #+#             */
/*   Updated: 2022/01/31 14:09:58 by tvogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_STRUCT_H
# define CUB_STRUCT_H

# include "cub3d.h"

typedef struct s_ray
{
	float	r_angle;
	float	wallHitX;
	float	wallHitY;
	float	distance;
	int		hit_vert;
	int		hit_hor;
	int		is_ray_up;
	int		is_ray_down;
	int		is_ray_right;
	int		is_ray_left;
	int		wall_content;

}	t_ray;

typedef struct s_player
{
	float	x;
	float	y;
	float	width;
	float	height;
	int		turn_dir;
	int		walk_dir;
	float	rotation_ang;
	float	walk_speed;
	float	turn_speed;
	int		seen;
	float	fov;
}	t_player;

typedef struct s_map
{
	int		map_height;
	int		map_width;
	char	*path;
	char	**map;
	int		map_begin;
}	t_map;

typedef struct s_textures
{
	int		saved;
	char	*path;
}	t_textures;

typedef struct s_colors
{
	int				seen;
	int				r;
	int				g;
	int				b;
	unsigned int	hex;
}	t_colors;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_graph
{
	void	*mlx;
	void	*win;
	t_img	img;
}	t_graph;

typedef struct s_config
{
	int			tile_size;
	int			map_fd;
	int			error;
	t_colors	floor;
	t_colors	ceiling;
	t_textures	textures[4];
	t_map		map;
	t_player	player;
	t_graph		graph;
	t_ray		rays[SCR_WIDTH];
}	t_config;

#endif
