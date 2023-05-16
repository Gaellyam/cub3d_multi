/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galamy <galamy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 08:43:11 by glamy             #+#    #+#             */
/*   Updated: 2023/05/16 12:20:11 by galamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_argument(int argc)
{
	if (argc > 2)
		ft_error("Error:\n Too many arguments given!");
	if (argc < 2)
		ft_error("Error:\n Too few arguments given!");
}

int	main(int argc, char **argv)
{
	t_game	game;

	check_argument(argc);
	init_setup(&game);
	open_cub(&game, argv[1]);
	read_info(&game);
	validate_info(&game);
	read_map(&game, game.line);
	validate_map(&game);
	check_all_setup(&game);
	run_game(&game);
	return (0);
}
