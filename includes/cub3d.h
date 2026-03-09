/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 13:24:01 by arpenel           #+#    #+#             */
/*   Updated: 2026/03/09 17:54:13 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "../Libft/includes/libft.h"

typedef struct  s_reso
{
    int width;
    int height;
}   t_reso;

typedef struct  s_rgb
{
    int    f[3];
    int    c[3];
}   t_rgb;

typedef struct  s_textures
{
    char    *no;
    char    *so;
    char    *we;
    char    *ea;
    char    *sprite;
} t_textures;

typedef struct  s_map
{
    int     start;
    char    **grid;
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
    t_reso      reso;
    t_map       map;
    t_textures  text;
    t_player    player;
    t_rgb       colors;
    char        **file;
    int         fd;
}   t_game;

// parsing.c
int parsing(t_game *game, int argc, char **argv);

// map.c
int parse_map(t_game *game);

// map_utils.c
int is_empty_line(char *str);

// file_utils.c
int file_to_tab(t_game *game, char **argv);

// identifiers.c
int parse_identifiers(t_game *game);

// free.c
void	free_file(t_game *game);
void	free_map(t_game *game);
void	free_textures(t_game *game);
void	free_all(t_game *game);


#endif