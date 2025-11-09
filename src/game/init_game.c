/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houarrak <houarrak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 15:14:03 by houarrak          #+#    #+#             */
/*   Updated: 2025/11/09 17:30:49 by houarrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

static void	load_texture(t_game *game, int id, char *path)
{
	void	*img;

	img = mlx_xpm_file_to_image(game->mlx, path, &game->tex_w[id],
			&game->tex_h[id]);
	if (!img)
		put_error("Failed to load texture\n");
	game->tex_img[id] = img;
	game->tex_addr[id] = mlx_get_data_addr(img, &game->tex_bpp[id],
			&game->tex_line_len[id], &game->tex_endian[id]);
	if (!game->tex_addr[id])
		put_error("Failed to get texture data addr\n");
}

static void init_mlx_and_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		put_error("MLX init failed\n");
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "cub3D");
	if (!game->win)
		put_error("Window creation failed\n");
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->img)
		put_error("Image creation failed\n");
	game->img_data = mlx_get_data_addr(game->img, &game->bpp, &game->line_len,
			&game->endian);
	if (!game->img_data)
		put_error("Image data addr failed\n");
}

static void init_textures(t_game *game)
{
	if (!game->config.no_tex || !game->config.so_tex || !game->config.we_tex
		|| !game->config.ea_tex)
		put_error("Missing texture path\n");
	load_texture(game, 0, game->config.no_tex);
	load_texture(game, 1, game->config.so_tex);
	load_texture(game, 2, game->config.we_tex);
	load_texture(game, 3, game->config.ea_tex);
}

static void init_game_keys(t_game *game)
{
	game->forward = 0;
	game->back = 0;
	game->strafe_left = 0;
	game->strafe_right = 0;
	game->rot_left = 0;
	game->rot_right = 0;
	game->need_redraw = 1;
}

void init_game(t_game *game)
{
	init_mlx_and_window(game);
	init_textures(game);
	init_game_keys(game);
}
