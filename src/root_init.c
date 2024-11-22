/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   root_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: envillan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:58:10 by envillan          #+#    #+#             */
/*   Updated: 2024/11/21 16:28:50 by envillan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	texture_load(t_game_root *root, t_img **img, char *path)
{
	int	width;
	int	height;

	*img = mlx_xpm_file_to_image(root->mlx_instance, path, &width, &height);
	if (*img == NULL)
		root_destroy(0, "can't load texture", 0);
	(*img)->width = width;
	(*img)->height = height;
}

static void	texture_init(t_game_root *root)
{
	texture_load(root, &root->player_img, "./textures/player.xpm");
	texture_load(root, &root->exit_image, "./textures/helicopter.xpm");
	texture_load(root, &root->collectable_image, "./textures/gas.xpm");
	texture_load(root, &root->wall_img, "./textures/wall.xpm");
	texture_load(root, &root->ground_img, "./textures/sand.xpm");
}

static void	render_init(t_game_root *root)
{
	root->mlx_instance = mlx_init();
	if (root->mlx_instance == 0)
		root_destroy(root, "can't load mlx", 0);
	root->mlx_window = mlx_new_window(root->mlx_instance, root->game->map_width
			* 40, root->game->map_height * 40, "so_long");
	if (root->mlx_window == 0)
		root_destroy(root, "can't create a window", 0);
	root->mlx_img = mlx_new_image(root->mlx_instance, root->game->map_width
			* 40, root->game->map_height * 40);
	if (root->mlx_img == 0)
		root_destroy(root, "can't create an image", 0);
}

static void	init_game(t_game_root *root, char *filename)
{
	root->game = (t_game_state *)malloc(sizeof(t_game_state));
	if (root->game == 0)
		root_destroy(root, "can't init game", errno);
	root->game->game_map = 0;
	root->game->collectables = 0;
	root->game->total_collectables = 0;
	root->game->total_exits = 0;
	root->game->total_players = 0;
	root->game->player_move = 0;
	root->game->collectibles_count = 0;
	root->game->player_up = 0;
	root->game->player_down = 0;
	root->game->player_left = 0;
	root->game->player_right = 0;
	map_init(root, filename);
}

t_game_root	*root_init(char *filename)
{
	t_game_root	*root;

	root = (t_game_root *)malloc(sizeof(t_game_root));
	if (root == 0)
		root_destroy(0, "can't allocate memory root_init", errno);
	root->game = 0;
	root->mlx_instance = 0;
	root->mlx_window = 0;
	root->mlx_img = 0;
	root->player_img = 0;
	root->exit_image = 0;
	root->collectable_image = 0;
	root->wall_img = 0;
	root->ground_img = 0;
	init_game(root, filename);
	render_init(root);
	texture_init(root);
	return (root);
}
