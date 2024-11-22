/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   root_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: envillan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:00:05 by envillan          #+#    #+#             */
/*   Updated: 2024/11/22 11:45:34 by envillan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	root_destroy_continue(t_game_root *root)
{
	if (root->mlx_instance != 0)
	{
		mlx_destroy_display(root->mlx_instance);
		free(root->mlx_instance);
		root->mlx_instance = 0;
	}
	if (root->game != NULL)
		free_game_resources(root->game);
}

void	root_destroy(t_game_root *root, char *error_message, int error_number)
{
	if (root != NULL)
	{
		if (root->ground_img != 0)
			mlx_destroy_image(root->mlx_instance, root->ground_img);
		if (root->wall_img != 0)
			mlx_destroy_image(root->mlx_instance, root->wall_img);
		if (root->collectable_image != 0)
			mlx_destroy_image(root->mlx_instance, root->collectable_image);
		if (root->exit_image != 0)
			mlx_destroy_image(root->mlx_instance, root->exit_image);
		if (root->player_img != 0)
			mlx_destroy_image(root->mlx_instance, root->player_img);
		if (root->mlx_img != 0)
			mlx_destroy_image(root->mlx_instance, root->mlx_img);
		if (root->mlx_window != 0)
			mlx_destroy_window(root->mlx_instance, root->mlx_window);
		root_destroy_continue(root);
		free(root);
	}
	exit_error(error_message, error_number);
}

void	exit_error(char *error_message, int error_number)
{
	if (error_message != 0 || error_number != 0)
		ft_putendl_fd("Error", 2);
	if (error_message != 0)
		ft_putstr_fd(error_message, 2);
	if (error_message != 0 && error_number != 0)
		ft_putstr_fd(": ", 2);
	if (error_number != 0)
		ft_putstr_fd(strerror(error_number), 2);
	if (error_message != 0 || error_number != 0)
	{
		ft_putendl_fd("", 2);
		exit(1);
	}
	exit(0);
}
