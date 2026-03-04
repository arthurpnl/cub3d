#include "../includes/cub3d.h"

int file_to_tab(t_game *game, char **argv)
{
    int count;
    int i;

    i = 0;
    count = count_line(argv);
    game->file = malloc(sizeof (char *) * (count + 1));
    if (!game->file)
        return (1);
    while((game->file[i] = get_next_line(game->fd)))
        i++;
    game->file[i] = NULL;
    close(game->fd);
    return (0);
}

int count_line(char **argv)
{
    char    *line;
    int fd;
    int count;

    count = 0;
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
        return (-1);
    while((line = get_next_line(fd)))
    {
        count++;
        free(line);
    }
    close(fd);
    return (count);
}