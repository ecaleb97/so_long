/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: envillan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:11:21 by envillan          #+#    #+#             */
/*   Updated: 2024/11/21 16:29:24 by envillan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	print_moves(t_game_root *root, int x, int y)
{
	if (root->game->player_position.x != x
		|| root->game->player_position.y != y)
	{
		root->game->player_move++;
		ft_putnbr_fd(root->game->player_move, 1);
		ft_putendl_fd("", 1);
	}
}

static void	is_collectable(t_game_root *root)
{
	int	i;

	i = 0;
	while (i < root->game->total_collectables)
	{
		if (root->game->collectables[i].x == root->game->player_position.x
			&& root->game->collectables[i].y == root->game->player_position.y)
		{
			root->game->collectables[i].x = -1;
			root->game->collectables[i].y = -1;
			root->game->collectibles_count++;
		}
		i++;
	}
}

void	update_game(t_game_root *root)
{
	int	x;
	int	y;

	x = root->game->player_position.x;
	y = root->game->player_position.y;
	if (root->game->player_up != 0)
		move_up(root, x, y);
	else if (root->game->player_down != 0)
		move_down(root, x, y);
	else if (root->game->player_left != 0)
		move_left(root, x, y);
	else if (root->game->player_right != 0)
		move_right(root, x, y);
	print_moves(root, x, y);
	is_collectable(root);
	render_frame(root);
	if (root->game->exit_position.x == root->game->player_position.x
		&& root->game->exit_position.y == root->game->player_position.y)
		if (root->game->total_collectables == root->game->collectibles_count)
			root_destroy(root, 0, 0);
}
