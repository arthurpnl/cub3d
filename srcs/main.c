/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 13:24:07 by arpenel           #+#    #+#             */
/*   Updated: 2026/03/04 15:33:42 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int main(int argc, char **argv)
{
    t_game game;

    if (parsing(&game, argc, argv) == 1)
    {
        free_file(&game);
        return (1);
    }
    int i = 0;
    int count = 0;
    while(game.file[i])
    {
        count = ft_strlen(game.file[i]);
        write(1, game.file[i], count);
        i++;
    }
    return (0);
}