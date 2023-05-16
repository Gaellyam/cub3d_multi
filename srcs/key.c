/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galamy <galamy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 12:04:17 by glamy             #+#    #+#             */
/*   Updated: 2023/05/16 12:17:17 by galamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit_game(game, "EXIT GAME\n", 0);
	if (keycode == KEY_W)
		move_front_back(game, game->player.move_speed);
	if (keycode == KEY_S)
		move_front_back(game, -game->player.move_speed);
	if (keycode == KEY_A)
		move_left_right(game, game->player.move_speed);
	if (keycode == KEY_D)
		move_left_right(game, -game->player.move_speed);
	if (keycode == KEY_RIGHT)
		rotate_player(&game->player, game->player.rot_speed);
	if (keycode == KEY_LEFT)
		rotate_player(&game->player, -game->player.rot_speed);
	return (0);
}

int	key_exit(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	exit_game(game, "EXIT GAME\n", 0);
	return (0);
}
