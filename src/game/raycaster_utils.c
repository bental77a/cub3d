/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houarrak <houarrak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 17:23:06 by houarrak          #+#    #+#             */
/*   Updated: 2025/11/09 17:23:57 by houarrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

static void init_ray_direction_and_map(t_ray *r, t_player *p, int x)
{
	double camera_x;

	camera_x = 2 * x / (double)WIDTH - 1;
	r->ray_dir_x = p->dir_x + p->plane_x * camera_x;
	r->ray_dir_y = p->dir_y + p->plane_y * camera_x;
	r->map_x = (int)p->x;
	r->map_y = (int)p->y;
	if (r->ray_dir_x == 0)
		r->delta_dist_x = 1e30;
	else
		r->delta_dist_x = fabs(1 / r->ray_dir_x);

	if (r->ray_dir_y == 0)
		r->delta_dist_y = 1e30;
	else
		r->delta_dist_y = fabs(1 / r->ray_dir_y);
}

static void init_ray_step_x(t_ray *r, t_player *p)
{
	if (r->ray_dir_x < 0)
	{
		r->step_x = -1;
		r->side_dist_x = (p->x - r->map_x) * r->delta_dist_x;
	}
	else
	{
		r->step_x = 1;
		r->side_dist_x = (r->map_x + 1.0 - p->x) * r->delta_dist_x;
	}
}

static void init_ray_step_y(t_ray *r, t_player *p)
{
	if (r->ray_dir_y < 0)
	{
		r->step_y = -1;
		r->side_dist_y = (p->y - r->map_y) * r->delta_dist_y;
	}
	else
	{
		r->step_y = 1;
		r->side_dist_y = (r->map_y + 1.0 - p->y) * r->delta_dist_y;
	}
}

void init_ray(t_ray *r, t_player *p, int x)
{
	init_ray_direction_and_map(r, p, x);
	init_ray_step_x(r, p);
	init_ray_step_y(r, p);
}