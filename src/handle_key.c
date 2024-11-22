/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: envillan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:42:01 by envillan          #+#    #+#             */
/*   Updated: 2024/11/21 16:26:56 by envillan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_press_key(int keycode, t_game_root *root)
{
	if (keycode == 65307)
		root_destroy(root, 0, 0);
	if (keycode == 119)
		root->game->player_up = 1;
	if (keycode == 115)
		root->game->player_down = 1;
	if (keycode == 97)
		root->game->player_left = 1;
	if (keycode == 100)
		root->game->player_right = 1;
	update_game(root);
	return (0);
}

int	handle_leave_key(int keycode, t_game_root *root)
{
	if (keycode == 119)
		root->game->player_up = 0;
	if (keycode == 115)
		root->game->player_down = 0;
	if (keycode == 97)
		root->game->player_left = 0;
	if (keycode == 100)
		root->game->player_right = 0;
	update_game(root);
	return (0);
}

int	handle_destroy_hook(int keycode, t_game_root *root)
{
	(void)keycode;
	(void)root;
	root_destroy(0, 0, 0);
	return (0);
}
