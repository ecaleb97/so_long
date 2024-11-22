/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: envillan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 22:04:15 by envillan          #+#    #+#             */
/*   Updated: 2024/11/21 16:26:25 by envillan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <errno.h>
# include <mlx.h>
# include <mlx_int.h>

typedef struct s_coordinates
{
	int				x;
	int				y;
}					t_coordinates;

typedef struct s_game
{
	int				**game_map;
	int				map_height;
	int				map_width;
	t_coordinates	player_position;
	int				player_up;
	int				player_down;
	int				player_left;
	int				player_right;
	int				player_move;
	int				collectibles_count;
	t_coordinates	exit_position;
	t_coordinates	*collectables;
	int				total_collectables;
	int				total_exits;
	int				total_players;
}					t_game_state;

typedef struct s_root
{
	void			*mlx_instance;
	void			*mlx_window;
	t_img			*mlx_img;
	t_game_state	*game;
	t_img			*player_img;
	t_img			*exit_image;
	t_img			*collectable_image;
	t_img			*wall_img;
	t_img			*ground_img;
}					t_game_root;

void				render_frame(t_game_root *root);
void				free_game_resources(t_game_state *game);
void				calculate_map_height(t_game_root *root, char *file);
void				map_init(t_game_root *root, char *filename);
void				map_is_valid(t_game_root *root, char *file);
void				map_parsing(t_game_root *root, char *file);
void				map_width(t_game_root *root, char *file);
unsigned int		get_pixel(t_img *img, int x, int y);
unsigned int		rgb_to_int(int alpha, int r, int g, int b);
void				draw_pixel(t_img *img, int x, int y, int color);
void				move_up(t_game_root *root, int x, int y);
void				move_down(t_game_root *root, int x, int y);
void				move_left(t_game_root *root, int x, int y);
void				move_right(t_game_root *root, int x, int y);
void				root_destroy(t_game_root *root, char *error_message,
						int error_number);
t_game_root			*root_init(char *filename);
t_coordinates		find_start_position(char **map, t_coordinates size);
void				update_game(t_game_root *root);
void				exit_error(char *error_message, int error_number);
int					is_accessible(t_game_root *root);
int					handle_press_key(int keycode, t_game_root *root);
int					handle_leave_key(int keycode, t_game_root *root);
int					handle_destroy_hook(int keycode, t_game_root *root);

#endif
