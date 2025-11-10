/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houarrak <houarrak@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:13:36 by mohben-t          #+#    #+#             */
/*   Updated: 2025/11/10 18:32:36 by houarrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

//# include "./minilibx-linux/mlx.h"
# include "get_next_line.h"
# include "libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <mlx.h>

# define WIDTH 1480
# define HEIGHT 944

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_UP 65362
# define KEY_DOWN 65364

# define PI 3.14159265359
# define MOVE_SPEED 0.08
# define ROT_SPEED 0.045

# define ERR_INVALID_PATH 1
# define ERR_INVALID_EXT 2
# define ERR_INVALID_RGB 3
# define ERR_INVALID_MAP 4
# define ERR_MISSING_TEXTURE 5
# define ERR_MISSING_COLOR 6
# define ERR_NO_PLAYER 7
# define ERR_MULTIPLAYER 8
# define ERR_UNKNOWN 99

# define COLOR_CEILING 0x87CEEB
# define COLOR_FLOOR 0x228B22
# define COLOR_WALL 0xFFD700

# define INVALID_PATH "Error\nInvalid file path"
# define INVALID_EXT "Error\nInvalid file extension"
# define USAGE_ERR "Error\nUsage: ./cub3D <file.cub>"

typedef struct s_config
{
	char		*no_tex;
	char		*so_tex;
	char		*we_tex;
	char		*ea_tex;
	int			floor[3];
	int			ceil[3];
	char		**map;
	int			map_h;
	int			map_w;
	int			player_x;
	int			player_y;
	char		player_dir;
}				t_config;

typedef struct s_player
{
	// float x;
	// float y;
	float		angle;
	double		x;
	double		y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	bool		key_up;
	bool		key_down;
	bool		key_left;
	bool		key_right;

	bool		left_rotate;
	bool		right_rotate;
}				t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*img_data;
	int			img_width;
	int			img_height;
	int			bpp;
	int			line_len;
	int			endian;
	char		**map;

	/* textures */
	void		*tex_img[4];
	char		*tex_addr[4];
	int			tex_w[4];
	int			tex_h[4];
	int			tex_bpp[4];
	int			tex_line_len[4];
	int			tex_endian[4];

	int			forward;
	int			back;
	int			strafe_left;
	int			strafe_right;
	int			rot_left;
	int			rot_right;

	double		last_time;
	int			need_redraw;
	t_config	config;
	t_player	player;
	int			x;
}				t_game;

typedef struct s_ray
{
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	int			step_x;
	int			step_y;
	int			side;
	double		perp_wall_dist;
}				t_ray;

typedef struct s_proj
{
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			tex_x;
	int			tex_y;
	double		step;
	double		tex_pos;
}				t_proj;

int				check_colors(t_config *config);
void			destroy_leaks(t_config *config);
void			destroy_game(t_game *game);
int				is_valid_map_char(char c);
int				handle_texture_entry(char *line, t_config *config, int *count);
int				handle_identifier_line(char **cursor, t_config *config);
void			measure_map(char **arr, t_config *config);
int				load_map_content(int fd, char **all_map);
int				append_line(char **buffer, char *line);
int				is_valid_map_char(char c);
void			skip_space(char **str);
int				get_len(char *str);
char			*get_path_textures(char **str);
void			free_textures(t_config *config);
int				get_colors(char **str, t_config *config);
int				get_color(char **str, int color[3]);
int				parse_component(char **str, int *value);
int				get_textures(char **str, t_config *config);
int				handle_identifier_line(char **cursor, t_config *config);
int				find_tall_line(char **str);
int				find_consecutive_newlines(const char *str);
char			*skip_lines(char **str);
char			*ft_strncpy(char *dest, char *src, unsigned int n);
bool			is_valid_neighbor(char cell, char pos_pl);
bool			check_map(int i, int j, char **map, char pos_pl);
int				check_last_zero(char **map, char pos_pl);
char			find_player_char(char **map);
int				check_map_walls(char **map, int height);
char			*get_next_line_from_string(char **map_str);
int				check_reachble(char **arr, t_config *config);
int				check_textures_and_color(char **map_str, t_config *config);
int				line_valide(char *line);
int				border_valid(char c);
void			free_array(char **arr);
char			**resize_line(char **arr, int size, int height);
char			*ft_strndup(char *s1, int size);
int				has_cub_extension(char *path);
int				is_player_char(char c);
int				parse_file(char *filename, t_config *config);
void			print_error(int code);
int				parse_map(char **map_cursor, t_config *config);
void			put_error(char *msg);
int				find_consecutive_newlines(const char *str);

// int		has_cub_extension(char *path);
// int		is_empty_line(char *line);
// int		is_player_char(char c);
// int		parse_file(char *filename, t_config *config);
// void	parse_rgb(int color[3], char *s);
// void	parse_identifier(t_config *cfg, char *line);
// int		is_map_line(char *line);
// char	**add_line_to_array(char **array, char *line);
// void	print_error(int code);
// void	validate_map(t_config *config);
// void	put_error(char *msg);

void			move_player(t_player *player);
int				rgb_to_int(int r, int g, int b);
void			draw_background(t_game *game);

// RAYCASTER
void			init_ray(t_ray *r, t_player *p, t_game *g);
int				get_texture_info(t_game *g, t_ray *r, t_proj *p);
unsigned int	get_tex_color(t_game *game, int tid, int tx, int ty);

// GAME
void			init_game(t_game *game);
void			init_player(t_player *player, t_config *config);
void			put_pixel(t_game *game, int x, int y, int color);
void			raycast(t_game *game, t_player *player);

// PLAYER
void			init_player_position(t_player *player, t_config *config);
void			set_dir_north(t_player *player);
void			set_dir_south(t_player *player);
void			set_dir_east(t_player *player);
void			set_dir_west(t_player *player);

int				is_empty_cell(t_game *game, double x, double y);
void			move_forward(t_game *game);
void			move_backward(t_game *game);
void			strafe_left(t_game *game);
void			strafe_right(t_game *game);
void			rotate_left(t_game *game);
void			rotate_right(t_game *game);
int				handle_linear_movement(t_game *game);
int				handle_rotation(t_game *game);

// HOOKS
int				key_press(int keycode, t_game *game);
int				key_release(int keycode, t_game *game);
int				update_loop(void *param);
int				close_window(t_game *game);
void			free_config(t_config *config);

int				is_empty_cell(t_game *game, double x, double y);

#endif
