/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glamy <glamy@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 12:16:56 by glamy             #+#    #+#             */
/*   Updated: 2020/11/29 18:38:18 by glamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_front_back(t_game *game, double move_speed)
{
	char	valx;
	char	valy;

	valx = game->setup.map[(int)game->player.posy][(int)(game->player.posx
	+ game->player.dir_x * move_speed)];
	valy = game->setup.map[(int)(game->player.posy
	+ game->player.dir_y * move_speed)][(int)game->player.posx];
	if (valx == '0')
		game->player.posx += game->player.dir_x * move_speed;
	if (valy == '0')
		game->player.posy += game->player.dir_y * move_speed;
}

void	move_left_right(t_game *game, double move_speed)
{
	char	valx;
	char	valy;

	valx = game->setup.map[(int)game->player.posy][(int)(game->player.posx
	+ game->player.dir_y * move_speed)];
	valy = game->setup.map[(int)(game->player.posy
	+ -game->player.dir_x * move_speed)][(int)game->player.posx];
	if (valx == '0')
		game->player.posx += game->player.dir_y * move_speed;
	if (valy == '0')
		game->player.posy += -game->player.dir_x * move_speed;
}

void	rotate_player(t_player *player, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = player->dir_x;
	player->dir_x = player->dir_x * cos(rot_speed)
	- player->dir_y * sin(rot_speed);
	player->dir_y = old_dir_x * sin(rot_speed)
	+ player->dir_y * cos(rot_speed);
	old_plane_x = player->plane_x;
	player->plane_x = player->plane_x * cos(rot_speed)
	- player->plane_y * sin(rot_speed);
	player->plane_y = old_plane_x * sin(rot_speed)
	+ player->plane_y * cos(rot_speed);
}
