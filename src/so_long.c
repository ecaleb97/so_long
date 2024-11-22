/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: envillan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:05:51 by envillan          #+#    #+#             */
/*   Updated: 2024/11/22 11:22:37 by envillan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_is_ber(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (file == 0)
		return (0);
	if (len < 5)
		return (0);
	if (ft_strcmp(file + len - 5, "/.ber") == 0)
		return (0);
	if (ft_strcmp(file + len - 4, ".ber") != 0)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game_root	*root;

	if (argc != 2)
		exit_error("Invalid arguments", 0);
	if (check_is_ber(argv[1]) == 0)
		exit_error("Invalid argument", 0);
	root = root_init(argv[1]);
	if (is_accessible(root) == 0)
		root_destroy(root, "Objects are not accessible", 0);
	render_frame(root);
	mlx_hook(root->mlx_window, 2, 1L << 0, handle_press_key, root);
	mlx_hook(root->mlx_window, 3, 1L << 1, handle_leave_key, root);
	mlx_hook(root->mlx_window, 17, 1L << 17, handle_destroy_hook, root);
	mlx_loop(root->mlx_instance);
	return (0);
}
