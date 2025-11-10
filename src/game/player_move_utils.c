/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohben-t <mohben-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 09:57:46 by mohben-t          #+#    #+#             */
/*   Updated: 2025/11/10 09:58:49 by mohben-t         ###   ########.fr       */
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
