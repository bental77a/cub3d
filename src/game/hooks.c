/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houarrak <houarrak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 18:20:09 by houarrak          #+#    #+#             */
/*   Updated: 2025/11/10 19:43:24 by houarrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->forward = 1;
	if (keycode == KEY_S)
		game->back = 1;
	if (keycode == KEY_A)
		game->strafe_left = 1;
	if (keycode == KEY_D)
		game->strafe_right = 1;
	if (keycode == KEY_LEFT)
		game->rot_left = 1;
	if (keycode == KEY_RIGHT)
		game->rot_right = 1;
	if (keycode == KEY_ESC)
	{
		destroy_game(game);
		exit(0);
	}
	game->need_redraw = 1;
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->forward = 0;
	if (keycode == KEY_S)
		game->back = 0;
	if (keycode == KEY_A)
		game->strafe_left = 0;
	if (keycode == KEY_D)
		game->strafe_right = 0;
	if (keycode == KEY_LEFT)
		game->rot_left = 0;
	if (keycode == KEY_RIGHT)
		game->rot_right = 0;
	return (0);
}

int	close_window(t_game *game)
{
	destroy_game(game);
	printf("Window closed — exiting Cub3D.\n");
	exit(0);
	return (0);
}

void	free_config(t_config *config)
{
	int	i;

	if (config->no_tex)
		free(config->no_tex);
	if (config->so_tex)
		free(config->so_tex);
	if (config->we_tex)
		free(config->we_tex);
	if (config->ea_tex)
		free(config->ea_tex);
	if (config->map)
	{
		i = 0;
		while (i < config->map_h)
		{
			if (config->map[i])
				free(config->map[i]);
			i++;
		}
		free(config->map);
	}
}
