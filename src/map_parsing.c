/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: envillan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:25:10 by envillan          #+#    #+#             */
/*   Updated: 2024/11/21 16:27:52 by envillan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_coordinates(t_game_root *root, char *file, int i, int *obj)
{
	if (file[i] == 'P')
	{
		root->game->player_position.x = i % (root->game->map_width + 1);
		root->game->player_position.y = i / (root->game->map_width + 1);
		file[i] = '0';
	}
	else if (file[i] == 'E')
	{
		root->game->exit_position.x = i % (root->game->map_width + 1);
		root->game->exit_position.y = i / (root->game->map_width + 1);
		file[i] = '0';
	}
	else if (file[i] == 'C')
	{
		root->game->collectables[*obj].x = i % (root->game->map_width + 1);
		root->game->collectables[*obj].y = i / (root->game->map_width + 1);
		file[i] = '0';
		(*obj)++;
	}
}

static void	free_matrix(t_game_root *root, char *file, int **matrix, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(matrix[i++]);
	free(matrix);
	root->game->game_map = 0;
	free(file);
	root_destroy(root, "Failed free matrix", errno);
}

void	map_parsing(t_game_root *root, char *file)
{
	int	i;
	int	j;
	int	k;
	int	obj;

	obj = 0;
	k = 0;
	j = -1;
	while (++j < root->game->map_height)
	{
		root->game->game_map[j] = (int *)malloc(sizeof(int)
				* root->game->map_width);
		if (root->game->game_map[j] == 0)
			free_matrix(root, file, root->game->game_map, j);
		i = 0;
		while (i < root->game->map_width)
		{
			get_coordinates(root, file, k, &obj);
			root->game->game_map[j][i++] = file[k++] - 48;
		}
		k++;
	}
}

t_coordinates	find_start_position(char **map, t_coordinates size)
{
	t_coordinates	pos;
	int				row;
	int				col;

	pos.y = -1;
	pos.x = -1;
	row = 0;
	while (row < size.x)
	{
		col = 0;
		while (col < size.x)
		{
			if (map[row][col] == 0)
			{
				pos.y = row;
				pos.x = col;
				return (pos);
			}
			col++;
		}
		row++;
	}
	return (pos);
}
