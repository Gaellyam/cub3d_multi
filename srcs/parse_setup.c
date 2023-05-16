/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galamy <galamy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 09:16:57 by glamy             #+#    #+#             */
/*   Updated: 2023/05/16 13:52:38 by galamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_check_size_res(t_game *game)
{
	int	w_max;
	int	h_max;
	int	width;
	int	height;

	w_max = 3840;
	h_max = 2160;
	width = game->setup.res_width;
	height = game->setup.res_height;
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
/*	if ((game->setup.res_height % TEX_HEIGHT) != 0)
	{
		if (game->setup.res_height > TEX_HEIGHT)
		{
			while ((width % TEX_HEIGHT) != 0)
				height--;
			game->setup.res_height = width;
		}
		else
			game->setup.res_height = TEX_HEIGHT;
	}*/
}

static int	isxmpfile(char *filename)
{
	int	ret;
	int	len;

	ret = 1;
	len = ft_strlen(filename);
	if (len >= 4)
		ret = ft_strncmp(filename + len - 4, ".xpm", 4);
	if (ret == 0)
		return (1);
	else
		return (0);
}

void	parse_texture(t_game *game, char *line, int flag)
{
	int		fd;
	char	**buf;

	buf = ft_split(line, ' ');
	if (!buf)
		ft_error("ERROR:\n Split fail");
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
	game->setup.param[flag] = flag;
}

void	parse_color(t_game *game, char *line, int flag)
{
	char	**buf;
	int		color;
	int		i;

	if (game->setup.param[flag] != -1)
		ft_error("ERROR:\n Double texture given!");
	if (line[0] == 'C' || line[0] == 'F')
		line += 1;
	buf = ft_split(line, ',');
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
