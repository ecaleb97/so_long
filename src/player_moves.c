/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: envillan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:54:11 by envillan          #+#    #+#             */
/*   Updated: 2024/11/21 16:27:57 by envillan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game_root *root, int x, int y)
{
	if (root->game->game_map[y - 1][x] == 0)
		root->game->player_position.y -= 1;
}

void	move_down(t_game_root *root, int x, int y)
{
	if (root->game->game_map[y + 1][x] == 0)
		root->game->player_position.y += 1;
}

void	move_left(t_game_root *root, int x, int y)
{
	if (root->game->game_map[y][x - 1] == 0)
		root->game->player_position.x -= 1;
}

void	move_right(t_game_root *root, int x, int y)
{
	if (root->game->game_map[y][x + 1] == 0)
		root->game->player_position.x += 1;
}
