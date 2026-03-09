/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 15:46:22 by arpenel           #+#    #+#             */
/*   Updated: 2026/03/09 17:19:44 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	skip_empty_lines(t_game *game)
{
	while (game->file[game->map.start] && is_empty_line(game->file[game->map.start]) == 1)
		game->map.start++;
	if (game->file[game->map.start] == NULL)
		return (-1);
	return (0);
}

static int	count_map_dimensions(t_game *game)
{
	int	count_line;
	int	current_len;
	int	max_width;

	count_line = game->map.start;
	max_width = 0;
	while (game->file[count_line] && is_empty_line(game->file[count_line]) == 0)
	{
		current_len = ft_strlen(game->file[count_line]);
		if (current_len > max_width)
			max_width = current_len;
		count_line++;
	}
	game->map.height = count_line - game->map.start;
	game->map.width = max_width;
	if (game->map.height == 0)
		return (-1);
	return (0);
}

int allocate_map(t_game *game)
{
    game->map.grid = malloc(sizeof(char *) * (game->map.height + 1));
    if (!game->map.grid)
        return (-1);
    game->map.grid[game->map.height] = NULL;
    return (0);
}

int copy_line(t_game *game)
{
    int i;
    int j;

    i = 0;
    while (i < game->map.height)
    {
        game->map.grid[i] = malloc(sizeof (char) * (game->map.width + 1));
        if (!game->map.grid[i])
            return (-1);
        j = 0;
        while (game->file[game->map.start + i][j] && j < game->map.width)
        {
            game->map.grid[i][j] = game->file[game->map.start + i][j];
            j++;
        }
        while(j < game->map.width)
        {
            game->map.grid[i][j] = '\0';
            j++;
        }
        i++;
    }
    return (0);
}

int	parse_map(t_game *game)
{
	if (skip_empty_lines(game) == -1)
		return (ft_putstr_fd("Error: No map found.\n", 2), -1);
	if (count_map_dimensions(game) == -1)
		return (ft_putstr_fd("Error: Invalid map dimensions.\n", 2), -1);
	if (allocate_map(game) == -1)
		return (ft_putstr_fd("Error: Malloc failed.\n", 2), -1);
	if (copy_line(game) == -1)
		return (ft_putstr_fd("Error: Failed to copy lines.\n", 2), -1);
	return (0);
}