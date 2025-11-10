/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohben-t <mohben-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 20:47:57 by houarrak          #+#    #+#             */
/*   Updated: 2025/11/10 10:07:33 by mohben-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

static void	dda_loop(t_game *g, t_ray *r)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (r->side_dist_x < r->side_dist_y)
		{
			r->side_dist_x += r->delta_dist_x;
			r->map_x += r->step_x;
			r->side = 0;
		}
		else
		{
			r->side_dist_y += r->delta_dist_y;
			r->map_y += r->step_y;
			r->side = 1;
		}
		if (r->map_x < 0 || r->map_y < 0 || r->map_y >= g->config.map_h
			|| r->map_x >= (int)ft_strlen(g->config.map[r->map_y]))
			break ;
		if (g->config.map[r->map_y][r->map_x] == '1')
			hit = 1;
	}
}

static void	perform_dda(t_game *g, t_ray *r)
{
	dda_loop(g, r);
	if (r->side == 0)
		r->perp_wall_dist = r->side_dist_x - r->delta_dist_x;
	else
		r->perp_wall_dist = r->side_dist_y - r->delta_dist_y;
}

static void	calculate_projection(t_proj *p, double dist)
{
	p->line_height = (int)(HEIGHT / dist);
	p->draw_start = -p->line_height / 2 + HEIGHT / 2;
	if (p->draw_start < 0)
		p->draw_start = 0;
	p->draw_end = p->line_height / 2 + HEIGHT / 2;
	if (p->draw_end >= HEIGHT)
		p->draw_end = HEIGHT - 1;
}

static void	draw_wall_column(t_game *g, t_ray *r, t_proj *p, int tex_id)
{
	int				y;
	int				tex_y;
	unsigned int	color;

	y = p->draw_start;
	while (y < p->draw_end)
	{
		tex_y = (int)p->tex_pos & (g->tex_h[tex_id] - 1);
		p->tex_pos += p->step;
		color = get_tex_color(g, tex_id, p->tex_x, tex_y);
		if (r->side == 1)
			color = (color >> 1) & 0x7F7F7F;
		put_pixel(g, g->x, y, color);
		y++;
	}
}

void	raycast(t_game *g, t_player *p)
{
	t_ray	r;
	t_proj	pr;
	int		tex_id;

	g->x = 0;
	while (g->x < WIDTH)
	{
		init_ray(&r, p, g);
		perform_dda(g, &r);
		calculate_projection(&pr, r.perp_wall_dist);
		tex_id = get_texture_info(g, &r, &pr);
		draw_wall_column(g, &r, &pr, tex_id);
		g->x++;
	}
}
