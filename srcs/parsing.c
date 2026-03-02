#include "../cub3d.h"

int parsing(t_game *game, int argc, char **argv)
{
    if (ext_check(argv[1]) == 1)
        return (perror("Wrong file extension, make sure to use a .cub\n"), 1);
    if (open_maps(argv[1], game) == 1)
        return (perror("Path of the map do not exist.\n"), 1);
}

int open_maps(char *str, t_game *game)
{
    game->map->fd = open(argv[1], O_RDONLY);
    if (game->map.fd < 0)
        return (1);
    return (0);
}

int ext_check(char  *str)
{
    int i;

    i = ft_strlen(str) - 1;
    while(str[i] != '.' && i > 0)
        i--
    if (ft_strncmp(str + i, ".cub", 4) != 0)
        return (1);
    return (0);
}

int **extract_map(t_game *game, char **argv)
{
    int count;

    count = count_line(*argv);
    while (get_next_line(tmpfd) != NULL)

}