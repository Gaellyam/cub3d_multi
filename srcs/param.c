/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galamy <galamy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 14:02:46 by glamy             #+#    #+#             */
/*   Updated: 2023/05/16 00:37:49 by galamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	iscubefile(char *filename)
{
	int ret;
	int len;

	ret = 1;
	len = ft_strlen(filename);
	if (len >= 4)
		ret = ft_strncmp(filename + len - 4, ".cub", 4);
	if (ret == 0)
		return (1);
	else
		return (0);
}

void		open_cub(t_game *game, char *filename)
{
	if (!(iscubefile(filename)))
		ft_error("ERROR:\n Not .cub extention!");
	game->fd = open(filename, O_RDONLY);
	if (game->fd == -1)
		ft_error("ERROR:\n No such cub file available");
}

int			check_param(t_game *game, char *info)
{
	
	if (info[0] == 'N' && info[1] == 'O' && info[2] == ' ')
		parse_texture(game, info, C_NO);
	else if (info[0] == 'S' && info[1] == 'O' && info[2] == ' ')
		parse_texture(game, info, C_SO);
	else if (info[0] == 'W' && info[1] == 'E' && info[2] == ' ')
		parse_texture(game, info, C_EA);
	else if (info[0] == 'E' && info[1] == 'A' && info[2] == ' ')
		parse_texture(game, info, C_WE);
	else if (info[0] == 'F' && info[1] == ' ')
		parse_color(game, info, C_F);
	else if (info[0] == 'C' && info[1] == ' ')
		parse_color(game, info, C_C);
	else
		return (MAP_START);
	return (0);
}

void		read_info(t_game *game)
{
	char	*line;
	int		flag;
	char	*info;

	while (get_next_line2(game->fd, &line) > 0)
	{
		if ((!line || line[0] == EMPTY_LINE) && flag != MAP_START)
			continue;
		if (!(info = ft_strtrim(line, " ")))
			ft_error("ERROR:\n Strtrim fail!");
		flag = check_param(game, info);
		free(info);
		if (flag == MAP_START)
			break ;
		free(line);
	}
	game->line = line;
}

void		validate_info(t_game *game)
{
	if (!game->setup.tex.path[C_NO] || !game->setup.tex.path[C_SO]
		|| !game->setup.tex.path[C_EA] || !game->setup.tex.path[C_WE]
		|| game->setup.tex.floor == -1 || game->setup.tex.ceiling == -1)
		ft_error("ERROR:\n Texture Info Missing");
}
