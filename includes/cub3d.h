/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 18:02:08 by tvogel            #+#    #+#             */
/*   Updated: 2022/01/24 10:21:27 by tvogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <mlx.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "get_next_line.h"

# define SCR_WIDTH 1280
# define SCR_HEIGHT 720

typedef struct s_rect
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	color;
}	t_rect;


typedef struct s_player
{
	int	x;
	int	y;
	int	seen;
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
	int			map_fd;
	int			error;
	t_colors	floor;
	t_colors	ceiling;
	t_textures	textures[4];
	t_map		map;
	t_player	player;
	t_graph		graph;
}	t_config;

int		init(t_config *conf);
int		parsing(t_config *conf, const char *argv[]);
int		check_file(t_config *conf, const char *file_path);
int		parse_settings(t_config *conf);
int		parse_colors(t_config *conf, char *line);
int		parse_map(t_config *conf);
int		save_map(t_config *conf);
int		settings_checker(t_config *conf);
int		is_map(t_config *conf, char *line, int print);
int		check_map(t_config *conf, t_map map);

int		start(t_config *conf, t_graph *g);
int		open_windows(t_graph *graph);
int		handle_input(int key, t_config *conf);
int		my_mlx_loop_hook(void);
int		close_window(t_graph *g);
void	my_mlx_pixel_put(t_graph graph, int x, int y, int color);

int		render(t_config *conf);
void	move_player(int	keysym, t_config *conf);

int		error_handling(t_config *conf, int return_value, char *message);

size_t	ft_strlen(const char *src);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_isdigit(int c);
int		ft_atoi(const char *nptr);
char	*ft_strdup(const char *src);

#endif
