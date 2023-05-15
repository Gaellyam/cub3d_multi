/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galamy <galamy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 12:20:56 by glamy             #+#    #+#             */
/*   Updated: 2023/05/15 22:29:54 by galamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int		is_blank_line(char *line)
{
	int		i;

	i = 0;
	if (!line)
		return (0);
	while (line[i])
	{
		if (!ft_isspace(line[i]))
			return (0);
		i++;
	}
	return (1);
}

void	read_map(t_game *game, char *line)
{
	game->lst = ft_lstnew(ft_strdup(line));
	free(line);
	while (get_next_line2(game->fd, &line) > 0)
	{
		if (is_blank_line(line) || line[0] == EMPTY_LINE)
		{
			free(line);
			ft_error_2(game,"ERROR:\n blank line in map",1);
		}
		if (line[0] == EMPTY_LINE)
			break ;
		ft_lstadd_back(&game->lst, ft_lstnew(ft_strdup(line)));
		free(line);
	}
	ft_lstadd_back(&game->lst, ft_lstnew(ft_strdup(line)));
	free(line);
	allocate_map(game, game->lst);
	store_map_as_array(game, game->lst);
	ft_lstclear(&(game->lst), free);
}

void	allocate_map(t_game *game, t_list *curr)
{
	int		i;
	int		j;

	game->setup.map_height = ft_lstsize(curr);
	game->setup.map_width = ft_long_cont_lst(curr);
	if (!(game->setup.map = malloc(sizeof(char *)
	* (game->setup.map_height + 1))))
		ft_error_2(game,"ERROR:\n Malloc Fail!",1);
	game->setup.map[game->setup.map_height] = NULL;
	i = 0;
	while (curr)
	{
		if (!(game->setup.map[i] = malloc(sizeof(char)
		* (game->setup.map_width + 1))))
			ft_error_2(game,"ERROR:\n Malloc Fail!",1);
		j = 0;
		while (j < game->setup.map_width)
		{
			game->setup.map[i][j] = ' ';
			j++;
		}
		game->setup.map[i][game->setup.map_width] = '\0';
		i++;
		curr = curr->next;
	}
}

void	store_map_as_array(t_game *game, t_list *curr)
{
	int		i;
	int		j;
	char	*content;

	i = 0;
	while (i < game->setup.map_height)
	{
		j = 0;
		content = (char *)curr->content;
		while (j < (int)ft_strlen(content))
		{
			if (!ft_isset(content[j], "NSWE01 \n") && content[j] != '\0')
				ft_error_2(game,"ERROR:\n Invalid Map Element Contained!",1);
			game->setup.map[i][j] = content[j];
			if (ft_isset(content[j], "NSWE"))
				init_player(game, i, j);
			j++;
		}
		curr = curr->next;
		i++;
	}
}
