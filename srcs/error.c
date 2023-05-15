/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galamy <galamy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 12:24:11 by glamy             #+#    #+#             */
/*   Updated: 2023/05/15 22:46:07 by galamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_error(char *str)
{
	ft_putstr(str);
	exit(0);
}

int	ft_error_2(t_game *game, char *str, int code)
{
	int	i;

	i = -1;
	while (++i < game->setup.map_height && game->setup.map[i])
	{
		free(game->setup.map[i]);
		game->setup.map[i] = NULL;
	}
	free(game->setup.map);
	game->setup.map = NULL;
	ft_putstr(str);
	exit(code);
}

void	ft_free_tab(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	exit_game(t_game *game, char *str, int code)
{
	if (game->win && game)
	{
		mlx_clear_window(game->mlx, game->win);
		mlx_destroy_window(game->mlx, game->win);
	}
	ft_error_2(game, str, code);
}
