/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 13:23:54 by arpenel           #+#    #+#             */
/*   Updated: 2026/03/04 13:23:55 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int open_maps(t_game *game, char **argv)
{
    game->fd = open(argv[1], O_RDONLY);
    if (game->fd < 0)
        return (1);
    return (0);
}

int ext_check(char  *str)
{
    int i;

    i = ft_strlen(str) - 1;
    while(str[i] != '.' && i > 0)
        i--;
    if (ft_strncmp(str + i, ".cub", 4) != 0)
        return (1);
    return (0);
}

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

int parsing(t_game *game, int argc, char **argv)
{
    if (argc != 2)
        return (ft_putstr_fd("You didn't send the require amount of args which is : 2 args.\n" , 2), 1);
    if (ext_check(argv[1]) == 1)
        return (ft_putstr_fd("Wrong file extension, make sure to use a .cub\n", 2), 1);
    if (open_maps(game, argv) == 1)
        return (ft_putstr_fd("Path of the map do not exist.\n", 2), 1);
    if  (file_to_tab(game, argv) == 1)
        return (ft_putstr_fd("Error while extracting the .cub file.\n", 2), 1);
    return (0);
}