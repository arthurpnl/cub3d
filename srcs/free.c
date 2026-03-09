/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 13:24:14 by arpenel           #+#    #+#             */
/*   Updated: 2026/03/09 15:51:40 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_file(t_game *game)
{
	int	i;

	i = 0;
	if (game->file)
	{
		while (game->file[i])
		{
			free(game->file[i]);
			i++;
		}
		free(game->file);
		game->file = NULL;
	}
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	if (game->map.grid)
	{
		while (game->map.grid[i])
		{
			free(game->map.grid[i]);
			i++;
		}
		free(game->map.grid);
		game->map.grid = NULL;
	}
}

void	free_textures(t_game *game)
{
	if (game->text.no)
		free(game->text.no);
	if (game->text.so)
		free(game->text.so);
	if (game->text.we)
		free(game->text.we);
	if (game->text.ea)
		free(game->text.ea);
	if (game->text.sprite)
		free(game->text.sprite);
}

void	free_all(t_game *game)
{
	free_file(game);
	free_map(game);
	free_textures(game);
}