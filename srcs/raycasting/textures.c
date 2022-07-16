/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvogel <tvogel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:35:45 by tvogel            #+#    #+#             */
/*   Updated: 2022/07/16 15:32:50 by tvogel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	fill_buffer(t_config *c, t_ray *r, int x)
{
	int			y;
	char		*texture;
	u_int32_t	color;
	int			*int_ptr;

	y = r->top;
	texture = mlx_get_data_addr(c->textures[1].img.mlx_img,
			&c->textures[1].img.bpp,
			&c->textures[1].img.line_len,
			&c->textures[1].img.endian);
	while (y < r->bottom)
	{
		r->texture_y = (int)r->tex_pos;
		r->tex_pos += r->tex_step;
		int_ptr = texture + (c->textures[1].img.line_len * r->texture_y
				+ r->texture_x * 4);
		color = *int_ptr;
		my_mlx_pixel_put(c->colors_buf, x, y, color);
		y++;
	}
}

void	calculate_textures(t_config *c, t_player *p, t_ray *r, int x)
{
	if (r->side == 0)
		r->wall_x = p->y + r->perp_wall_dist * r->rayDir_y;
	else
		r->wall_x = p->x + r->perp_wall_dist * r->rayDir_x;
	r->wall_x -= floor(r->wall_x);
	r->texture_x = (int)(r->wall_x * 64);
	if (r->side == 0 && r->rayDir_x > 0)
		r->texture_x = 64 - r->texture_x - 1;
	else if (r->side == 1 && r->rayDir_y < 0)
		r->texture_x = 64 - r->texture_x - 1;
	r->tex_step = 1.0 * 64 / r->line_height;
	r->tex_pos = (r->top - SCR_HEIGHT / 2 + r->line_height / 2) * r->tex_step;
	fill_buffer(c, r, x);
}

void	init_textures(t_config *c)
{
	t_textures	*current;
	int			i;

	i = 0;
	while (i < 4)
	{
		current = &c->textures[i];
		current->img.mlx_img = mlx_xpm_file_to_image(c->graph.mlx,
				current->path, &current->width, &current->height);
		printf("%s %i %i\n", current->path, current->width, current->height);
		i++;
	}
}