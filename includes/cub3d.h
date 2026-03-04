/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 13:24:01 by arpenel           #+#    #+#             */
/*   Updated: 2026/03/04 16:17:20 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "../Libft/includes/libft.h"

typedef struct  s_rgb
{
    
}   t_rgb;

typedef struct  s_textures
{
    char    *no;
    char    *so;
    char    *we;
    char    *ea;
} t_textures;

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
    t_textures   text;
    t_player    player;
    char        **file;
    int         fd;
}   t_game;

// parsing.c
int parsing(t_game *game, int argc, char **argv);
int ext_check(char  *str);
int open_file(t_game *game, char **argv);

// file_utils.c
int file_to_tab(t_game *game, char **argv);
int count_line(char **argv);

// free.c
void    free_file(t_game *game);


#endif