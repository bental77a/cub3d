/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houarrak <houarrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:12:15 by mohben-t          #+#    #+#             */
/*   Updated: 2025/10/05 18:43:52 by houarrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/cub.h"


static void	print_config(t_config *config)
{
    int	i;

    printf("\n=== PARSING RESULTS ===\n");
    printf("NO texture: %s\n", config->no_tex ? config->no_tex : "NULL");
    printf("SO texture: %s\n", config->so_tex ? config->so_tex : "NULL");
    printf("WE texture: %s\n", config->we_tex ? config->we_tex : "NULL");
    printf("EA texture: %s\n", config->ea_tex ? config->ea_tex : "NULL");
    
    printf("Floor RGB: %d,%d,%d\n", config->floor[0], config->floor[1], config->floor[2]);
    printf("Ceiling RGB: %d,%d,%d\n", config->ceil[0], config->ceil[1], config->ceil[2]);
    
    printf("Map size: %d x %d\n", config->map_w, config->map_h);
    printf("Player position: (%d, %d) facing %c\n", 
        config->player_x, config->player_y, config->player_dir ? config->player_dir : '?');
    
    printf("\nMap:\n");
    if (config->map)
    {
        i = 0;
        while (i < config->map_h)
        {
            printf("[%d] %s\n", i, config->map[i]);
            i++;
        }
    }
    printf("======================\n\n");
}

static void	init_config(t_config *config)
{
    config->no_tex = NULL;
    config->so_tex = NULL;
    config->we_tex = NULL;
    config->ea_tex = NULL;
    config->floor[0] = -1;
    config->floor[1] = -1;
    config->floor[2] = -1;
    config->ceil[0] = -1;
    config->ceil[1] = -1;
    config->ceil[2] = -1;
    config->map = NULL;
    config->map_h = 0;
    config->map_w = 0;
    config->player_x = -1;
    config->player_y = -1;
    config->player_dir = '\0';
}


int main(int ac, char **av)
{
    t_game game;

    if (ac != 2)
        return (ft_putendl_fd(USAGE_ERR, 2), 1);
    if (has_cub_extension(av[1]))
        return (1);
    init_config(&game.config);
    if (parse_file(av[1], &game.config))
        return (1);
    validate_map(&game.config);
    print_config(&game.config);
    init_game(&game);
    init_player(&game.player, &game.config);

    draw_background(&game);

    raycast(&game, &game.player);
    mlx_key_hook(game.win, handle_keypress, &game);
    mlx_put_image_to_window(game.mlx, game.win, game.img, 0, 0);

    mlx_loop(game.mlx);
    return (0);
}

