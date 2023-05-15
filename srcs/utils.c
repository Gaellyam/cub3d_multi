/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galamy <galamy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 10:29:22 by glamy             #+#    #+#             */
/*   Updated: 2023/05/16 00:17:41 by galamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_isset(char c, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_long_cont_lst(t_list *lst)
{
	int max;

	max = -1;
	while (lst)
	{
		if (max < (int)ft_strlen((char *)lst->content))
			max = (int)ft_strlen((char *)lst->content);
		lst = lst->next;
	}
	return (max);
}

int	check_color(char **buf, int i)
{
	int	color;
	int colors[3];
	int j;

	j = 0;
	while (j < 3)
		colors[j++] = 0;
	if (i == 3)
	{
		if (buf[0] == NULL || buf[1] == NULL || buf[2] == NULL)
			ft_error("Error:\n Color arguments not given!");
		if (!str_isdigit(buf[0]) || !str_isdigit(buf[1])
		|| !str_isdigit(buf[2]))
			ft_error("Error:\n Digit color not valid given!");
		colors[0] = atoi(buf[0]);
		colors[1] = atoi(buf[1]);
		colors[2] = atoi(buf[2]);
		if ((colors[0] < 0 || colors[0] > 255) || (colors[1] < 0 ||
		colors[1] > 255) || (colors[2] < 0 || colors[2] > 255))
			ft_error("Error:\n RGB color not valid");
	}
	color = colors[0] * 256 * 256 + colors[1] * 256 + colors[2];
	return (color);
}

int	check_argcolor(char *line)
{
	int num;
	int i;

	i = 0;
	num = 0;
	while (line[i])
		if (line[i++] == ',')
			num++;
	return (num);
}

int	str_isdigit(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
