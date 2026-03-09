/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 13:23:54 by arpenel           #+#    #+#             */
/*   Updated: 2026/03/09 17:54:35 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	ext_check(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (str[i] != '.' && i > 0)
		i--;
	if (ft_strncmp(str + i, ".cub", 4) != 0)
		return (1);
	return (0);
}

static int	open_file(t_game *game, char **argv)
{
	game->fd = open(argv[1], O_RDONLY);
	if (game->fd < 0)
		return (1);
	return (0);
}

int	parsing(t_game *game, int argc, char **argv)
{
	if (argc != 2)
		return (ft_putstr_fd("Error: Wrong number of arguments.\n", 2), 1);
	if (ext_check(argv[1]) == 1)
		return (ft_putstr_fd("Error: Wrong file extension (use .cub).\n", 2), 1);
	if (open_file(game, argv) == 1)
		return (ft_putstr_fd("Error: Cannot open file.\n", 2), 1);
	if (file_to_tab(game, argv) == 1)
		return (ft_putstr_fd("Error: Failed to read file.\n", 2), 1);
	if (parse_identifiers(game) == -1)
		return (ft_putstr_fd("Error: Invalid identifiers.\n", 2), 1);
	if (parse_map(game) == -1)
		return (ft_putstr_fd("Error: Invalid map.\n", 2), 1);
	return (0);
}