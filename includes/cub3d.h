#ifndef CUB3D_H
#define CUB3D_H

#include "../Libft.h"

typedef struct  s_sprites
{

} t_sprites;

typedef struct  s_map
{
    int fd;
    char    **map;
    int height;
    int width;

} t_map;

typedef struct  s_player
{
    int x;
    int y;
    char    dir;
}   t_player;

typedef struct  s_game
{
    t_map       map;
    t_sprites   text;
    t_player    player;
}   t_game;

#endif