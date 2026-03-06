/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifiers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 15:09:06 by arpenel           #+#    #+#             */
/*   Updated: 2026/03/06 16:06:02 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int parse_textures(char **dest, char *src)
{
    *dest = ft_strdup(src);
    if (!*dest)
        return (1);
    return (0);
}

int parse_colors(int *dest, char *src)
{
    int     i;
    char    **tmp;

    i = 0;
    while (src[i] == ' ' || src[i] == '\t')
        i++;
    tmp = ft_split(src + i, ',');
    if (!tmp)
        return (1);
    i = 0;
    while(tmp[i])
    {
        dest[i] = ft_atoi(tmp[i]);
        free(tmp[i]);
        i++;
    }
    free(tmp);
    return (0);
}

int check_identifier(t_game *game, int i)
{
    if (ft_strncmp(game->file[i], "R ", 2) == 0)
        return (parse_resolution(&game->reso, game->file[i] + 2));
    else if (ft_strncmp(game->file[i], "S ", 2) == 0)
        return (parse_textures(&game->text.sprite, game->file[i] + 2));
    else if (ft_strncmp(game->file[i], "NO ", 3) == 0)
        return (parse_textures(&game->text.no, game->file[i] + 3));
    else if (ft_strncmp(game->file[i], "SO ", 3) == 0)
        return (parse_textures(&game->text.so, game->file[i] + 3));
    else if (ft_strncmp(game->file[i], "WE ", 3) == 0)
        return (parse_textures(&game->text.we, game->file[i] + 3));
    else if (ft_strncmp(game->file[i], "EA ", 3) == 0)
        return (parse_textures(&game->text.ea, game->file[i] + 3));
    else if (ft_strncmp(game->file[i], "F ", 2) == 0)
        return (parse_colors(game->colors.f, game->file[i] + 2));
    else if (ft_strncmp(game->file[i], "C ", 2) == 0)
        return (parse_colors(game->colors.c, game->file[i] + 2));
    return (2);
}

int parse_identifiers(t_game *game)
{
    int i;
    int count;
    int ret;

    i = 0;
    count = 0;
    while (game->file[i])
    {
        ret = check_identifier(game, i);
        if (ret == 1)
            return (-1);
        if (ret == 0)
            count++;
        if (count == 8)
            return (i + 1);
        i++;
    }
    return (-1);
}



