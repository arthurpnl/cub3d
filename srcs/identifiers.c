#include "../includes/cub3d.h"

int parse_identifiers(t_game *game)
{
    int i;

    i = 0;
    while(game->file[i])
    {
        if(ft_strncmp(game->file[i], "NO ", 3) == 0)
            // appeler la fonction qui stock le path
        else if(ft_strncmp(game->file[i], "SO ", 3) == 0)
            // appeler la fonction qui stock le path 
        else if(ft_strncmp(game->file[i], "WE ", 3) == 0)
            // appeler la fonction qui stock le path
        else if(ft_strncmp(game->file[i], "EA ", 3) == 0)
            // appeler la fonction qui stock le path
        else if(ft_strncmp(game->file[i], "F ", 2) == 0)
            // appeler la fonction qui stock path couleur 
        else if(ft_strcnmp(game->file[i], "C ", 2) == 0);
        i++;
    }

}

parse textures 

parse colors 



