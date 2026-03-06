/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 15:46:22 by arpenel           #+#    #+#             */
/*   Updated: 2026/03/06 17:00:18 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int skip_n_allocate(t_game *game, int map_start)
{
    int count_line;

    count_line = map_start;
    while (game->file[map_start] && is_empty_line(game->file[map_start]) == 1)
        map_start++;
    if (game->file[map_start] == NULL)
        return (1);
    else
        game->map.start = map_start;
    while (game->file[count_line] && is_empty_line(game->file[count_line]) == 0)
        count_line++;
    game->map.grid = malloc(sizeof(char *) * (count_line - map_start + 1));
    if (!game->map.grid)
        return (1);
    return (0);
}

int parse_map(t_game *game, int map_start)
{
    if (skip_n_allocate(game, map_start) == 1)
        return (ft_putstr_fd("Error : xxx\n", 2), 1);
}