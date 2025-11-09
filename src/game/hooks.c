/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houarrak <houarrak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 18:20:09 by houarrak          #+#    #+#             */
/*   Updated: 2025/11/09 15:13:03 by houarrak         ###   ########.fr       */
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
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	game->need_redraw = 1;
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		game->forward = 0;
	if (keycode == KEY_S || keycode == KEY_DOWN)
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
	if (game->img)
		mlx_destroy_image(game->mlx, game->img);

	int i = 0;
	while (i < 4)
	{
		if (game->tex_img[i])
			mlx_destroy_image(game->mlx, game->tex_img[i]);
		i++;
	}

	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	// Free any other resources (map, config, ...)
	// free_config(&game->config);
	printf("Window closed — exiting Cub3D.\n");

	exit(0);
	return (0);
}
