/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnaud <arnaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:55:18 by arnaud            #+#    #+#             */
/*   Updated: 2022/06/28 16:27:46 by arnaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	delfirst_node(t_list **q)
{
	t_list	*temp;

	temp = *q;
	*q = (*q)->next;
	free(temp);
}

void	add_nodes(t_list *q)
{
	ft_lstadd_back(&q, ft_lstnew(q->x + 1, q->y));
	ft_lstadd_back(&q, ft_lstnew(q->x, q->y + 1));
	if (q->x)
		ft_lstadd_back(&q, ft_lstnew(q->x - 1, q->y));
	if (q->y)
		ft_lstadd_back(&q, ft_lstnew(q->x, q->y - 1));
}

void	check_inside(t_map map, t_list *q)
{
	if (map.map[q->y][q->x] == '0'
		|| map.map[q->y][q->x] == 'E'
		|| map.map[q->y][q->x] == 'N'
		|| map.map[q->y][q->x] == 'W'
		|| map.map[q->y][q->x] == 'S')
	{
		map.map[q->y][q->x] = 'x';
		add_nodes(q);
	}
}

int	error_found(t_map map, t_list *q)
{
	if (ft_isspace(map.map[q->y][q->x])
		|| !ft_isprint(map.map[q->y][q->x])
		|| (map.map[q->y][q->x] == 'x' &&
		(q->x == 0 || q->x == map.map_width - 1
		|| q->y == 0 || q->y == map.map_height - 1)))
	{
		return (1);
	}
	return (0);
}

int	floodfill(t_config *conf, t_map m)
{
	int		i;
	int		j;
	t_list	*q;
	t_map	map;

	map = m;
	if (map.map[0] == 0)
		return (1);
	q = ft_lstnew(conf->player.x, conf->player.y);
	add_nodes(q);
	while (ft_lstsize(q))
	{
		check_inside(map, q);
		if (error_found(map, q))
		{
			ft_lstclear(&q, free);
			return (1);
		}
		delfirst_node(&q);
	}
	ft_lstclear(&q, free);
	return (0);
}
