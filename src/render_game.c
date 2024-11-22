/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: envillan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:32:01 by envillan          #+#    #+#             */
/*   Updated: 2024/11/21 16:28:35 by envillan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_image(t_game_root *root, t_img *img, int x, int y)
{
	unsigned int	color;
	int				i;
	int				j;

	j = 0;
	while (j < 40)
	{
		i = 0;
		while (i < 40)
		{
			color = get_pixel(img, i, j);
			if (color != rgb_to_int(0, 255, 255, 255))
				draw_pixel(root->mlx_img, x + i, y + j, color);
			i++;
		}
		j++;
	}
}

static void	draw_objects(t_game_root *root, int x, int y)
{
	int	i;

	if (root->game->exit_position.x == x && root->game->exit_position.y == y)
		draw_image(root, root->exit_image, x * 40, y * 40);
	i = -1;
	while (++i < root->game->total_collectables)
		if (root->game->collectables[i].x == x
			&& root->game->collectables[i].y == y)
			draw_image(root, root->collectable_image, x * 40, y * 40);
	if (root->game->player_position.x == x
		&& root->game->player_position.y == y)
		draw_image(root, root->player_img, x * 40, y * 40);
}

static void	render_map(t_game_root *root)
{
	int	x;
	int	y;

	y = 0;
	while (y < root->game->map_height)
	{
		x = 0;
		while (x < root->game->map_width)
		{
			if (root->game->game_map[y][x] == 1)
				draw_image(root, root->wall_img, x * 40, y * 40);
			else
				draw_image(root, root->ground_img, x * 40, y * 40);
			draw_objects(root, x, y);
			x++;
		}
		y++;
	}
}

void	render_frame(t_game_root *root)
{
	render_map(root);
	mlx_put_image_to_window(root->mlx_instance, root->mlx_window, root->mlx_img,
		0, 0);
}
