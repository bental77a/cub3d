/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houarrak <houarrak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 14:02:59 by houarrak          #+#    #+#             */
/*   Updated: 2025/11/09 22:47:26 by houarrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int is_empty_cell(t_game *game, double x, double y)
{
	int map_x = (int)x;
	int map_y = (int)y;
    if (map_x < 0 || map_y < 0 || map_y >= game->config.map_h)
        return 0;
    if (map_x >= (int)ft_strlen(game->config.map[map_y]))
        return 0;
    return (game->config.map[map_y][map_x] != '1');
}

int	rgb_to_int(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

void	put_pixel(t_game *game, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = game->img_data + (y * game->line_len + x * (game->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_background(t_game *game)
{
	int	ceil;
	int	floor;

	int x, y;
	ceil = rgb_to_int(game->config.ceil[0], game->config.ceil[1],
			game->config.ceil[2]);
	floor = rgb_to_int(game->config.floor[0], game->config.floor[1],
			game->config.floor[2]);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < HEIGHT / 2)
				put_pixel(game, x, y, ceil);
			else
				put_pixel(game, x, y, floor);
			x++;
		}
		y++;
	}
}

void	destroy_game(t_game *game)
{
	int i;

	if (!game)
		return ;
	if (game->img)
		mlx_destroy_image(game->mlx, game->img);
	i = 0;
	while (i < 4)
	{
		if (game->tex_img[i])
			mlx_destroy_image(game->mlx, game->tex_img[i]);
		i++;
	}
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	free_textures(&game->config);
	if (game->config.map)
		free_array(game->config.map);
}
