/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mov.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houarrak <houarrak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 18:18:55 by houarrak          #+#    #+#             */
/*   Updated: 2025/11/10 14:15:53 by houarrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	strafe_left(t_game *game)
{
	double	speed;
	double	nx;
	double	ny;

	speed = MOVE_SPEED;
	nx = game->player.x - game->player.plane_x * speed;
	ny = game->player.y - game->player.plane_y * speed;
	if (is_empty_cell(game, nx, game->player.y))
		game->player.x = nx;
	if (is_empty_cell(game, game->player.x, ny))
		game->player.y = ny;
}

void	strafe_right(t_game *game)
{
	double	speed;
	double	nx;
	double	ny;

	speed = MOVE_SPEED;
	nx = game->player.x + game->player.plane_x * speed;
	ny = game->player.y + game->player.plane_y * speed;
	if (is_empty_cell(game, nx, game->player.y))
		game->player.x = nx;
	if (is_empty_cell(game, game->player.x, ny))
		game->player.y = ny;
}

void	rotate_left(t_game *game)
{
	double	rot;
	double	old_dir_x;
	double	old_plane_x;

	rot = -ROT_SPEED;
	old_dir_x = game->player.dir_x;
	old_plane_x = game->player.plane_x;
	game->player.dir_x = old_dir_x * cos(rot) - game->player.dir_y * sin(rot);
	game->player.dir_y = old_dir_x * sin(rot) + game->player.dir_y * cos(rot);
	game->player.plane_x = old_plane_x * cos(rot) - game->player.plane_y
		* sin(rot);
	game->player.plane_y = old_plane_x * sin(rot) + game->player.plane_y
		* cos(rot);
}

static void	render_frame(t_game *game)
{
	draw_background(game);
	raycast(game, &game->player);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	game->need_redraw = 0;
}

int	update_loop(void *param)
{
	t_game	*game;
	int		moved;

	game = (t_game *)param;
	moved = 0;
	moved |= handle_linear_movement(game);
	moved |= handle_rotation(game);
	if (moved || game->need_redraw)
		render_frame(game);
	return (0);
}
