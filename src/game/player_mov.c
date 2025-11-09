/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mov.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houarrak <houarrak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 18:18:55 by houarrak          #+#    #+#             */
/*   Updated: 2025/11/09 17:28:23 by houarrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

#define MOVE_SPEED 0.08
#define ROT_SPEED  0.045

void move_forward(t_game *game)
{
	double speed = MOVE_SPEED;
    double nx = game->player.x + game->player.dir_x * speed;
    double ny = game->player.y + game->player.dir_y * speed;
    if (is_empty_cell(game, nx, game->player.y))
        game->player.x = nx;
    if (is_empty_cell(game, game->player.x, ny))
        game->player.y = ny;
}

void move_backward(t_game *game)
{
    double speed = MOVE_SPEED;
    double nx = game->player.x - game->player.dir_x * speed;
    double ny = game->player.y - game->player.dir_y * speed;
    if (is_empty_cell(game, nx, game->player.y))
        game->player.x = nx;
    if (is_empty_cell(game, game->player.x, ny))
        game->player.y = ny;
}

void strafe_left(t_game *game)
{
    double speed = MOVE_SPEED;
    double nx = game->player.x - game->player.plane_x * speed;
    double ny = game->player.y - game->player.plane_y * speed;
    if (is_empty_cell(game, nx, game->player.y))
        game->player.x = nx;
    if (is_empty_cell(game, game->player.x, ny))
        game->player.y = ny;
}

void strafe_right(t_game *game)
{
    double speed = MOVE_SPEED;
    double nx = game->player.x + game->player.plane_x * speed;
    double ny = game->player.y + game->player.plane_y * speed;
    if (is_empty_cell(game, nx, game->player.y))
        game->player.x = nx;
    if (is_empty_cell(game, game->player.x, ny))
        game->player.y = ny;
}

void rotate_left(t_game *game)
{
    double rot = -ROT_SPEED;
    double old_dir_x = game->player.dir_x;
    double old_plane_x = game->player.plane_x;
    game->player.dir_x = old_dir_x * cos(rot) - game->player.dir_y * sin(rot);
    game->player.dir_y = old_dir_x * sin(rot) + game->player.dir_y * cos(rot);
    game->player.plane_x = old_plane_x * cos(rot) - game->player.plane_y * sin(rot);
    game->player.plane_y = old_plane_x * sin(rot) + game->player.plane_y * cos(rot);
}

void rotate_right(t_game *game)
{
    double rot = ROT_SPEED;
    double old_dir_x = game->player.dir_x;
    double old_plane_x = game->player.plane_x;
    game->player.dir_x = old_dir_x * cos(rot) - game->player.dir_y * sin(rot);
    game->player.dir_y = old_dir_x * sin(rot) + game->player.dir_y * cos(rot);
    game->player.plane_x = old_plane_x * cos(rot) - game->player.plane_y * sin(rot);
    game->player.plane_y = old_plane_x * sin(rot) + game->player.plane_y * cos(rot);
}

int update_loop(void *param)
{
    t_game *game = (t_game *)param;

    int moved = 0;
    if (game->forward)      { move_forward(game); moved = 1; }
    if (game->back)         { move_backward(game); moved = 1; }
    if (game->strafe_left)  { strafe_left(game); moved = 1; }
    if (game->strafe_right) { strafe_right(game); moved = 1; }
    if (game->rot_left)     { rotate_left(game); moved = 1; }
    if (game->rot_right)    { rotate_right(game); moved = 1; }

    if (moved || game->need_redraw)
    {
        draw_background(game);
        raycast(game, &game->player);
        mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
        game->need_redraw = 0;
    }
    return (0);
}
