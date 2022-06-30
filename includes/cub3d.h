/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiju-du <abiju-du@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 18:02:08 by tvogel            #+#    #+#             */
/*   Updated: 2022/06/27 19:35:46 by tvogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define SCR_WIDTH 480
# define SCR_HEIGHT 250
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <limits.h>
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


typedef struct s_list t_list;
struct s_list
{
    int x;
    int y;
    t_list *next;
    t_list *prev;
};


int		init(t_config *conf);

int		open_windows(t_graph *graph);
int		my_mlx_loop_hook(void);
int		close_window(t_graph *g);
void	my_mlx_pixel_put(t_img img, int x, int y, int color);
void	clear_buffer(t_config *c);

int		keydown(int keysym, t_config *conf);
int		keyup(int keysym, t_config *conf);
void	move_forward(t_player *p, t_map *m);
void	move_backward(t_player *p, t_map *m);
void	rotate(t_player *p, int direction);

int		error_handling(t_config *conf, int return_value, char *message);

// utils
size_t	ft_strlen(const char *src);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_isdigit(int c);
int		ft_atoi(const char *nptr);
char	*ft_strdup(const char *src);
int		ft_isspace(const char c);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstadd_front(t_list **alst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*));
t_list	*ft_lstnew(int x, int y);
int	    ft_lstsize(t_list *lst);
int		ft_isprint(int c);

#endif
