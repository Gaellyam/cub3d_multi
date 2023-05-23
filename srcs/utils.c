/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galamy <galamy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 10:29:22 by glamy             #+#    #+#             */
/*   Updated: 2023/05/23 12:55:08 by galamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_isset(char c, char *str)
{
	int	i;

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
	int	max;

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
	int	colors[3];
	int	j;

	j = 0;
	while (j < 3)
		colors[j++] = -1;
	if (!buf[0] || !buf[1] || !buf[2] || is_blank_line(buf[0])
		|| is_blank_line(buf[1]) || is_blank_line(buf[2]))
		ft_error("Error:\n Color arguments not given!");
	if (i == 3)
	{
		if (!str_isdigit(buf[0]) || !str_isdigit(buf[1])
			|| !str_isdigit(buf[2]))
			ft_error("Error:\n Digit color not valid given!");
		colors[0] = ft_atoi2(buf[0]);
		colors[1] = ft_atoi2(buf[1]);
		colors[2] = ft_atoi2(buf[2]);
		if ((colors[0] == -1 || colors[1] == -1 || colors[2] == -1))
			ft_error("Error:\n RGB color not valid");
	}
	color = colors[0] * 256 * 256 + colors[1] * 256 + colors[2];
	return (color);
}

int	str_isdigit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
