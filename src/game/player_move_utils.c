/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houarrak <houarrak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 09:57:46 by mohben-t          #+#    #+#             */
/*   Updated: 2025/11/10 14:16:00 by houarrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	move_forward(t_game *game)
{
	double	speed;
	double	nx;
	double	ny;

	speed = MOVE_SPEED;
	nx = game->player.x + game->player.dir_x * speed;
	ny = game->player.y + game->player.dir_y * speed;
	if (is_empty_cell(game, nx, game->player.y))
		game->player.x = nx;
	if (is_empty_cell(game, game->player.x, ny))
		game->player.y = ny;
}

void	move_backward(t_game *game)
{
	double	speed;
	double	nx;
	double	ny;

	speed = MOVE_SPEED;
	nx = game->player.x - game->player.dir_x * speed;
	ny = game->player.y - game->player.dir_y * speed;
	if (is_empty_cell(game, nx, game->player.y))
		game->player.x = nx;
	if (is_empty_cell(game, game->player.x, ny))
		game->player.y = ny;
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
int	handle_linear_movement(t_game *game)
{
	int	moved;

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
	return (moved);
}

int	handle_rotation(t_game *game)
{
	int	moved;

	moved = 0;
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
	return (moved);
}