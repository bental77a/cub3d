/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mov.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohben-t <mohben-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 18:18:55 by houarrak          #+#    #+#             */
/*   Updated: 2025/11/10 09:58:56 by mohben-t         ###   ########.fr       */
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

void	rotate_right(t_game *game)
{
	double	rot;
	double	old_dir_x;
	double	old_plane_x;

	rot = ROT_SPEED;
	old_dir_x = game->player.dir_x;
	old_plane_x = game->player.plane_x;
	game->player.dir_x = old_dir_x * cos(rot) - game->player.dir_y * sin(rot);
	game->player.dir_y = old_dir_x * sin(rot) + game->player.dir_y * cos(rot);
	game->player.plane_x = old_plane_x * cos(rot) - game->player.plane_y
		* sin(rot);
	game->player.plane_y = old_plane_x * sin(rot) + game->player.plane_y
		* cos(rot);
}

int	update_loop(void *param)
{
	t_game	*game;
	int		moved;

	game = (t_game *)param;
	moved = 0;
	if (game->forward)
	{
		move_forward(game);
		moved = 1;
	}
	if (game->back)
	{
		move_backward(game);
		moved = 1;
	}
	if (game->strafe_left)
	{
		strafe_left(game);
		moved = 1;
	}
	if (game->strafe_right)
	{
		strafe_right(game);
		moved = 1;
	}
	if (game->rot_left)
	{
		rotate_left(game);
		moved = 1;
	}
	if (game->rot_right)
	{
		rotate_right(game);
		moved = 1;
	}
	if (moved || game->need_redraw)
	{
		draw_background(game);
		raycast(game, &game->player);
		mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
		game->need_redraw = 0;
	}
	return (0);
}
