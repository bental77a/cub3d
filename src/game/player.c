/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houarrak <houarrak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 18:54:19 by houarrak          #+#    #+#             */
/*   Updated: 2025/11/09 15:24:30 by houarrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/cub.h"


static void init_player_direction(t_player *player, t_config *config)
{
    if (config->player_dir == 'N')
        set_dir_north(player);
    else if (config->player_dir == 'S')
        set_dir_south(player);
    else if (config->player_dir == 'E')
        set_dir_east(player);
    else if (config->player_dir == 'W')
        set_dir_west(player);
}

static void init_player_keys(t_player *player)
{
    player->key_up = false;
    player->key_down = false;
    player->key_left = false;
    player->key_right = false;
    player->left_rotate = false;
    player->right_rotate = false;
}

void init_player(t_player *player, t_config *config)
{
    init_player_position(player, config);
    init_player_direction(player, config);
    init_player_keys(player);
}

