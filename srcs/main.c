/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpenel <arpenel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 13:24:07 by arpenel           #+#    #+#             */
/*   Updated: 2026/03/09 17:56:25 by arpenel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


static void	debug_print(t_game *game)
{
	int	i;

	i = 0;
	ft_printf("\n=== DEBUG: File content ===\n");
	while (game->file[i])
	{
		ft_printf("%s", game->file[i]);
		i++;
	}
	ft_printf("\n=== DEBUG: Identifiers ===\n");
	ft_printf("NO: %s\n", game->text.no);
	ft_printf("SO: %s\n", game->text.so);
	ft_printf("WE: %s\n", game->text.we);
	ft_printf("EA: %s\n", game->text.ea);
	ft_printf("F: %d,%d,%d\n", game->colors.f[0], \
		game->colors.f[1], game->colors.f[2]);
	ft_printf("C: %d,%d,%d\n", game->colors.c[0], \
		game->colors.c[1], game->colors.c[2]);
	ft_printf("\n=== DEBUG: Map ===\n");
	ft_printf("Map start: %d\n", game->map.start);
	ft_printf("Map height: %d\n", game->map.height);
	ft_printf("Map width: %d\n", game->map.width);
	i = 0;
	while (game->map.grid && game->map.grid[i])
	{
		ft_printf("[%d]: %s\n", i, game->map.grid[i]);
		i++;
	}
}

int main(int argc, char **argv)
{
    t_game game;

    if (parsing(&game, argc, argv) == 1)
    {
        free_file(&game);
        return (1);
    }
    debug_print(&game);
    return (0);
}