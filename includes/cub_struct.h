/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 10:53:03 by tvogel            #+#    #+#             */
/*   Updated: 2022/07/27 10:56:33 by tvogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_STRUCT_H
# define CUB_STRUCT_H

# include "cub3d.h"

typedef struct s_ray
{
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	int		map_x;
	int		map_y;
	double	sidedist_x;
	double	sidedist_y;
	double	delta_x;
	double	delta_y;
	double	perp_wall_dist;
	double	step_x;
	double	step_y;
	int		hit;
	int		side;
	int		top;
	int		bottom;
	int		color;
	double	wall_x;
	int		texture_x;
	int		texture_y;
	double	tex_pos;
	double	tex_step;
	int		line_height;
}	t_ray;

typedef struct s_player
{
	float	x;
	float	y;
	float	width;
	float	height;
	int		turn_dir;
	int		walk_dir;
	double	rotation_speed;
	double	walk_speed;
	float	turn_speed;
	int		seen;
	float	fov;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	char	dir_init;
}	t_player;

typedef struct s_map
{
	int		map_height;
	int		map_width;
	char	*path;
	char	**map;
	int		map_begin;
}	t_map;

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

typedef struct s_textures
{
	int		saved;
	char	*path;
	t_img	img;
	int		width;
	int		height;
}	t_textures;

typedef struct s_graph
{
	void	*mlx;
	void	*win;
	t_img	img;
}	t_graph;

typedef struct s_config
{
	int			map_fd;
	int			error;
	t_colors	floor;
	t_colors	ceiling;
	t_textures	textures[4];
	t_map		map;
	t_player	player;
	t_graph		graph;
	t_ray		rays[SCR_WIDTH];
	t_img		colors_buf;
}	t_config;

#endif
