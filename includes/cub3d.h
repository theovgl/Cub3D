/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 18:02:08 by tvogel            #+#    #+#             */
/*   Updated: 2022/01/27 11:02:56 by tvogel           ###   ########.fr       */
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
# include "cub_struct.h"
# include "get_next_line.h"
# include "parsing.h"
# include "graphics.h"
# include "raycast.h"

# define SCR_WIDTH 1280
# define SCR_HEIGHT 720

int		init(t_config *conf);

int		start(t_config *conf, t_graph *g);
int		open_windows(t_graph *graph);
int		handle_input(int key, t_config *conf);
int		my_mlx_loop_hook(void);
int		close_window(t_graph *g);
void	my_mlx_pixel_put(t_graph graph, int x, int y, int color);

int		render(t_config *conf);
void	raycast(t_config *conf, t_player *player);
void	move_player(int keysym, t_config *conf);

int		error_handling(t_config *conf, int return_value, char *message);

size_t	ft_strlen(const char *src);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_isdigit(int c);
int		ft_atoi(const char *nptr);
char	*ft_strdup(const char *src);

#endif
