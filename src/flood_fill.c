/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: envillan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:47:35 by envillan          #+#    #+#             */
/*   Updated: 2024/11/21 16:26:54 by envillan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	fill(char **tab, t_coordinates size, t_coordinates position,
		char target)
{
	if (position.y < 0 || position.x < 0 || position.y >= size.y
		|| position.x >= size.x)
		return ;
	if (tab[position.y][position.x] == 'F'
		|| tab[position.y][position.x] != target)
		return ;
	tab[position.y][position.x] = 'F';
	fill(tab, size, (t_coordinates){position.x, position.y - 1}, target);
	fill(tab, size, (t_coordinates){position.x, position.y + 1}, target);
	fill(tab, size, (t_coordinates){position.x - 1, position.y}, target);
	fill(tab, size, (t_coordinates){position.x + 1, position.y}, target);
}

static void	flood_fill(char **tab, t_coordinates size, t_coordinates begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
}

static void	free_map_duplicate(char **map, int height)
{
	int	i;

	i = 0;
	while (i < height)
		free(map[i++]);
	free(map);
}

static char	**duplicate_map(t_game_root *root)
{
	char	**dup;
	int		i;
	int		j;

	i = 0;
	dup = malloc(sizeof(char *) * root->game->map_height);
	if (!dup)
		return (NULL);
	while (i < root->game->map_height)
	{
		dup[i] = malloc(sizeof(char) * (root->game->map_width + 1));
		if (dup[i] == NULL)
			free_map_duplicate(dup, i);
		j = -1;
		while (++j < root->game->map_width)
			dup[i][j] = root->game->game_map[i][j];
		dup[i++][root->game->map_width] = '\0';
	}
	return (dup);
}

int	is_accessible(t_game_root *root)
{
	char			**map_copy;
	int				i;
	t_coordinates	size;
	t_coordinates	start;

	size.x = root->game->map_width;
	size.y = root->game->map_height;
	map_copy = duplicate_map(root);
	start = find_start_position(map_copy, size);
	flood_fill(map_copy, size, start);
	if (map_copy[root->game->exit_position.y][root->game->exit_position.x] != 'F')
		return (free_map_duplicate(map_copy, size.y), 0);
	i = -1;
	while (++i < root->game->total_collectables)
	{
		if (map_copy[root->game->collectables[i].y][root->game->collectables[i].x] != 'F')
			return (free_map_duplicate(map_copy, size.y), 0);
	}
	if (map_copy[root->game->player_position.y][root->game->player_position.x] != 'F')
		return (free_map_duplicate(map_copy, size.y), 0);
	return (free_map_duplicate(map_copy, size.y), 1);
}
