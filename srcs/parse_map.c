/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galamy <galamy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 10:47:24 by glamy             #+#    #+#             */
/*   Updated: 2023/05/16 12:09:45 by galamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	validate_map(t_game *game)
{
	if (!game->setup.map_width || !game->setup.map_height)
		ft_error_2(game, "ERROR:\n Invalid Map Parsing", 1);
	if (game->player.dir == '\0')
		ft_error_2(game, "ERROR:\n No Player Position Given!", 1);
	validate_map_horizontal(game, game->setup.map,
		game->setup.map_width, game->setup.map_height);
	validate_map_vertical(game, game->setup.map,
		game->setup.map_width, game->setup.map_height);
}

void	validate_map_horizontal(t_game *game, char **map, int width, int height)
{
	int	x;
	int	y;

	y = 0;
	while (y < height)
	{
		if (map[y][0] != ' ' && map[y][0] != WALL)
			ft_error_2(game, "ERROR:\n Not Surronded Walls!(Left)", 1);
		x = 1;
		while (x < width)
		{
			while (x < width && map[y][x] == ' ')
				x++;
			if (x == width)
				break ;
			if (map[y][x - 1] == ' ' && map[y][x] != WALL)
				ft_error_2(game, "ERROR:\n Not Surronded alls!(Left)", 1);
			while (x < width && map[y][x] != ' ')
				x++;
			if (map[y][x - 1] != WALL)
				ft_error_2(game, "ERROR:\n Not Surronded Walls!(Right)", 1);
		}
		y++;
	}
}

void	validate_map_vertical(t_game *game, char **map, int width, int height)
{
	int	x;
	int	y;

	x = 0;
	while (x < width)
	{
		if (map[0][x] != ' ' && map[0][x] != WALL)
			ft_error_2(game, "ERROR:\n Not Surronded Walls!(Upper)", 1);
		y = 1;
		while (y < height)
		{
			while (y < height && map[y][x] == ' ')
				y++;
			if (y == height)
				break ;
			if (map[y - 1][x] == ' ' && map[y][x] != WALL)
				ft_error_2(game, "ERROR:\n Not Surronded Walls!(Upper)", 1);
			while (y < height && map[y][x] != ' ')
				y++;
			if (map[y - 1][x] != WALL)
				ft_error_2(game, "ERROR:\n Not Surronded Walls!(Bottom)", 1);
		}
		x++;
	}
}
