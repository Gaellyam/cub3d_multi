/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galamy <galamy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:50:00 by glamy             #+#    #+#             */
/*   Updated: 2023/05/16 15:08:12 by galamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	run_game(t_game *game)
{
	game->win = mlx_new_window(game->mlx,
			game->setup.res_width, game->setup.res_height, "cub3d");
	if (!game->win)
		exit_game(game, "Error\n Creating windows fail.\n", 1);
	mlx_hook(game->win, EVENT_KEY_PRESS, 0, &key_press, game);
	mlx_hook(game->win, EVENT_KEY_EXIT, 0, &key_exit, game);
	mlx_loop_hook(game->mlx, &main_loop, game);
	mlx_loop(game->mlx);
}

int	main_loop(t_game *game)
{
	raycast(game);
	render(game);
	return (0);
}

void	raycast(t_game *game)
{
	int	i;

	i = 0;
	set_ceiling_floor(game);
	while (i < game->setup.res_width)
	{
		init_ray(game, &game->player, &game->ray, i);
		calculate_step(&game->player, &game->ray);
		perform_dda(&game->setup, &game->ray);
		calculate_wall_distance(&game->player, &game->ray);
		calculate_wall_height(game, &game->ray);
		set_wall_tex(&game->player, &game->ray);
		set_wall_color(game, &game->ray, i);
		game->n_buffer[i] = game->ray.perpwalldist;
		i++;
	}
}

void	render(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (j < game->setup.res_height)
	{
		i = 0;
		while (i < game->setup.res_width)
		{
			game->img.data[game->setup.res_width * j + i] = game->buf[j][i];
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}
