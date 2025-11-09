/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houarrak <houarrak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:24:01 by houarrak          #+#    #+#             */
/*   Updated: 2025/11/09 15:24:41 by houarrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void init_player_position(t_player *player, t_config *config)
{
    player->x = config->player_x + 0.5;
    player->y = config->player_y + 0.5;
}

void set_dir_north(t_player *player)
{
    player->dir_x = 0;
    player->dir_y = -1;
    player->plane_x = 0.66;
    player->plane_y = 0;
}

void set_dir_south(t_player *player)
{
    player->dir_x = 0;
    player->dir_y = 1;
    player->plane_x = -0.66;
    player->plane_y = 0;
}

void set_dir_east(t_player *player)
{
    player->dir_x = 1;
    player->dir_y = 0;
    player->plane_x = 0;
    player->plane_y = 0.66;
}

void set_dir_west(t_player *player)
{
    player->dir_x = -1;
    player->dir_y = 0;
    player->plane_x = 0;
    player->plane_y = -0.66;
}