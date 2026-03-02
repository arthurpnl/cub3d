#include "cub3d.h"

int line_count(char **argv)
{
    char    *line;
    int fd;
    int count;

    count = 0;
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
        return (1);
    while(line = get_next_line(fd))
    {
        count++;
        free(line);
    }
    close(fd);
    return (count);
}