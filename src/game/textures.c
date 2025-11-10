/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohben-t <mohben-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 17:21:46 by houarrak          #+#    #+#             */
/*   Updated: 2025/11/10 09:51:36 by mohben-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

unsigned int	get_tex_color(t_game *game, int tid, int tx, int ty)
{
	char	*pixel;
	int		bpp;

	if (tid < 0 || tid > 3)
		return (0);
	bpp = game->tex_bpp[tid] / 8;
	pixel = game->tex_addr[tid] + ty * game->tex_line_len[tid] + tx * bpp;
	return (*(unsigned int *)pixel);
}

static int	get_tex_id(t_ray *r)
{
	if (r->side == 1)
	{
		if (r->ray_dir_y > 0)
			return (1);
		else
			return (0);
	}
	else
	{
		if (r->ray_dir_x > 0)
			return (3);
		else
			return (2);
	}
}

static double	get_wall_x(t_game *g, t_ray *r)
{
	if (r->side == 0)
		return (g->player.y + r->perp_wall_dist * r->ray_dir_y);
	else
		return (g->player.x + r->perp_wall_dist * r->ray_dir_x);
}

int	get_texture_info(t_game *g, t_ray *r, t_proj *p)
{
	int		tex_id;
	double	wall_x;

	tex_id = get_tex_id(r);
	wall_x = get_wall_x(g, r);
	wall_x -= floor(wall_x);
	p->tex_x = (int)(wall_x * g->tex_w[tex_id]);
	if ((r->side == 0 && r->ray_dir_x > 0) || (r->side == 1
			&& r->ray_dir_y < 0))
		p->tex_x = g->tex_w[tex_id] - p->tex_x - 1;
	p->step = 1.0 * g->tex_h[tex_id] / p->line_height;
	p->tex_pos = (p->draw_start - HEIGHT / 2 + p->line_height / 2) * p->step;
	return (tex_id);
}
