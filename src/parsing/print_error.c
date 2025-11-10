/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohben-t <mohben-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:13:16 by mohben-t          #+#    #+#             */
/*   Updated: 2025/11/10 09:43:55 by mohben-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	put_error(char *msg)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
	exit(1);
}

void	print_error(int code)
{
	if (code == ERR_INVALID_PATH)
		put_error("Invalid file path");
	else if (code == ERR_INVALID_EXT)
		put_error("Invalid file extension");
	else if (code == ERR_INVALID_RGB)
		put_error("Invalid RGB values");
	else if (code == ERR_INVALID_MAP)
		put_error("Invalid map");
	else if (code == ERR_MISSING_TEXTURE)
		put_error("Missing texture");
	else if (code == ERR_MISSING_COLOR)
		put_error("Missing color");
	else if (code == ERR_NO_PLAYER)
		put_error("No player found");
	else if (code == ERR_MULTIPLAYER)
		put_error("Multiple players");
	else
		put_error("Unknown error");
}

int	check_colors(t_config *config)
{
	if (config->floor[0] == -1 && config->floor[1] == -1 && config->floor[2]
		== -1)
	{
		destroy_leaks(config);
		put_error("Floor color not set");
		return (1);
	}
	if (config->ceil[0] == -1 && config->ceil[1] == -1 && config->ceil[2] == -1)
	{
		destroy_leaks(config);
		put_error("Ceiling color not set");
		return (1);
	}
	return (0);
}
