/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galamy <galamy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 09:16:57 by glamy             #+#    #+#             */
/*   Updated: 2023/05/15 22:51:26 by galamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
/*
static void	ft_check_size_res(t_game *game)
{
	int w_max;
	int h_max;
	int width;

	w_max = 100;
	h_max = 100;
	width = game->setup.res_width;
	mlx_get_screen_size(game->mlx, &w_max, &h_max);
	if (game->setup.res_width > w_max)
		game->setup.res_width = w_max;
	if (game->setup.res_height > h_max)
		game->setup.res_height = h_max;
	if ((game->setup.res_width % TEX_WIDTH) != 0)
	{
		if (game->setup.res_width > TEX_WIDTH)
		{
			while ((width % TEX_WIDTH) != 0)
				width--;
			game->setup.res_width = width;
		}
		else
			game->setup.res_width = TEX_WIDTH;
	}
}

*/
static int	isxmpfile(char *filename)
{
	int ret;
	int len;

	ret = 1;
	len = ft_strlen(filename);
	if (len >= 4)
		ret = ft_strncmp(filename + len - 4, ".xpm", 4);
	if (ret == 0)
		return (1);
	else
		return (0);
}

void		parse_texture(t_game *game, char *line, int flag)
{
	int		fd;
	char	**buf;

	if (!(buf = ft_split(line, ' ')))
		ft_error_2(game,"ERROR:\n Split fail",1);
	if (buf[2])
		ft_error("Error:\n Too many arguments given for texture!");
	if (game->setup.param[flag] != -1)
		ft_error("ERROR:\n Double texture given!");
	if (!line || !isxmpfile(buf[1]))
		ft_error("ERROR:\n Image format is not .xpm");
	fd = open(buf[1], O_RDONLY);
	if (fd == -1)
		ft_error("ERROR:\n Texture paths available!");
	close(fd);
	game->setup.tex.path[flag] = ft_strdup(buf[1]);
	if(!game->setup.tex.path[flag])
		ft_error("Error moussaka\n");
	game->setup.param[flag] = flag;
}

void		parse_color(t_game *game, char *line, int flag)
{
	char	**buf;
	int		color;
	int		num_coma;
	int		i;

	num_coma = check_argcolor(line);
	if (num_coma != 2)
		ft_error("ERROR:\n Argument color not valid");
	if (game->setup.param[flag] != -1)
		ft_error("ERROR:\n Double texture given!");
	if (line[0] == 'C' || line[0] == 'F')
		line += 1;
	buf = ft_split(line, ',');
	if (!buf)
		ft_free_tab(buf);
	i = 0;
	while (buf[i])
	{
		buf[i] = ft_strtrim(buf[i], " ");
		i++;
	}
	color = check_color(buf, i);
	if (flag == C_F)
		game->setup.tex.floor = color;
	else if (flag == C_C)
		game->setup.tex.ceiling = color;
	game->setup.param[flag] = flag;
}
