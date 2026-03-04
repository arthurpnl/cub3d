/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 13:24:01 by arpenel           #+#    #+#             */
/*   Updated: 2026/03/04 13:24:03 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "../Libft/includes/libft.h"

typedef struct  s_sprites
{

} t_sprites;

typedef struct  s_map
{
    char    **map;
    int     height;
    int     width;

} t_map;

typedef struct  s_player
{
    int     x;
    int     y;
    char    dir;
}   t_player;

typedef struct  s_game
{
    t_map       map;
    t_sprites   text;
    t_player    player;
    char        **file;
    int         fd;
}   t_game;

// parsing.c
int parsing(t_game *game, int argc, char **argv);

// utils_map.c
int count_line(char **argv);

// free.c
void    free_file(t_game *game);


#endif