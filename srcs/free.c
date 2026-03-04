/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 13:24:14 by arpenel           #+#    #+#             */
/*   Updated: 2026/03/04 13:24:15 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    free_file(t_game *game)
{
    int i;

    i = 0;

    if (game->file)
    {
        while(game->file[i])
        {
            free(game->file[i]);
            i++;
        }
        free(game->file);
    }
}